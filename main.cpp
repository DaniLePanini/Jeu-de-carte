#include "Berserker.h"
// Bibliothèques MySQL pour la connexion et les requêtes
sql::mysql::MySQL_Driver *driver;  // Pointeur vers le driver MySQL
sql::Connection *con;              // Pointeur vers la connexion MySQL

// Fonction pour récupérer un équipement par son ID et appliquer les bonus
void appliquerEquipement(int id, personnage_de_base* personnage) {
    // Initialisation de variables pour stocker les informations de l'équipement
    string equipement = "";
    int bonus_vie = 0, bonus_attaque = 0, bonus_defense = 0, bonus_vitesse = 0;

    // Préparation de la requête pour récupérer les détails de l'équipement en fonction de son ID
    sql::PreparedStatement *stmt = con->prepareStatement("SELECT type, bonus_vie, bonus_attaque, bonus_defense, bonus_vitesse FROM equipement WHERE id = ?");
    stmt->setInt(1, id);  // Remplace le paramètre de la requête avec l'ID de l'équipement
    sql::ResultSet *res = stmt->executeQuery();  // Exécute la requête et récupère les résultats

    // Vérification des résultats
    if (res->next()) {
        // Extraction des valeurs du résultat
        equipement = res->getString("type");
        bonus_vie = res->getInt("bonus_vie");
        bonus_attaque = res->getInt("bonus_attaque");
        bonus_defense = res->getInt("bonus_defense");
        bonus_vitesse = res->getInt("bonus_vitesse");

        // Application des bonus directement aux statistiques du personnage
        personnage->ajouterPV(bonus_vie);
        personnage->ajouterAttaque(bonus_attaque);
        personnage->ajouterDefense(bonus_defense);
        personnage->ajouterVitesse(bonus_vitesse);

        // Affichage de l'équipement et des bonus appliqués
        cout << "Equipement: " << equipement << endl;
        cout << "Bonus appliqués - Vie: " << bonus_vie << ", Attaque: " << bonus_attaque
             << ", Défense: " << bonus_defense << ", Vitesse: " << bonus_vitesse << endl;
    } else {
        cout << "Aucun équipement trouvé pour l'ID: " << id << endl;
    }

    delete res;   // Libère la mémoire de l'objet ResultSet
    delete stmt;  // Libère la mémoire de l'objet PreparedStatement
}

int main() {
    // Informations de connexion à la base de données
    string host = "localhost";
    string login = "etudiant";
    string pwd = "Passciel2";
    string nombase = "equipement"; 

    // Initialisation de la bibliothèque MySQL
    driver = sql::mysql::get_mysql_driver_instance();  // Obtient l'instance du driver MySQL
    con = driver->connect("localhost", login, pwd);  // Crée une connexion au serveur MySQL avec l'utilisateur et le mot de passe
    con->setSchema(nombase);  // Sélectionne la base de données à utiliser

    // Vérification de la connexion réussie
    cout << "Connexion à la base de données réussie." << endl;

    // Instantiation des personnages
    Snowqueen p1;  // Instance de Snowqueen
    Berserker p2;  // Instance de Berserker
    personnage_de_base* joueur1;  // Pointeur vers le joueur 1
    personnage_de_base* joueur2;  // Pointeur vers le joueur 2
    personnage_de_base* perso1;
    personnage_de_base* perso2;

    // Choix des personnages
    int choix1, choix2;
    cout << "Choisissez votre personnage pour le joueur 1:" << endl;
    cout << "1. Snowqueen" << endl;
    cout << "2. Berserker" << endl;
    cout << "Entrez votre choix: ";
    cin >> choix1;

    cout << "Choisissez votre personnage pour le joueur 2:" << endl;
    cout << "1. Snowqueen" << endl;
    cout << "2. Berserker" << endl;
    cout << "Entrez votre choix: ";
    cin >> choix2;

    // Attribution des personnages en fonction des choix
    if (choix1 == 1) perso1 = &p1;
    else if (choix1 == 2) perso1 = &p2;
    else perso1 = &p1;  // Par défaut Snowqueen si le choix est invalide

    if (choix2 == 1) perso2 = &p1;
    else if (choix2 == 2) perso2 = &p2;
    else perso2 = &p1;  // Par défaut Snowqueen si le choix est invalide

    // Détermination du personnage ayant la vitesse la plus élevée pour commencer
    personnage_de_base* j1;
    personnage_de_base* j2;
    if (perso1->getSpeed() > perso2->getSpeed()) {
        j1 = perso1;
        j2 = perso2;
    } else {
        j1 = perso2;
        j2 = perso1;
    }

    cout << "Le joueur " << (j1 == perso1 ? 1 : 2) << " commence avec " << (j1 == &p1 ? "Snowqueen" : "Berserker") << endl;

    // Attribution des équipements de base
    appliquerEquipement(4, j1);  // Heaume
    appliquerEquipement(5, j1);  // Gilet
    appliquerEquipement(6, j1);  // Gants
    appliquerEquipement(7, j1);  // Bottes

    // Choix de l'arme
    int choixArme;
    cout << "Choisissez une arme:" << endl;
    cout << "1. Epee" << endl;
    cout << "2. Dagues" << endl;
    cout << "3. Baton" << endl;
    cout << "Entrez votre choix: ";
    cin >> choixArme;

    // Appliquer l'arme choisie
    appliquerEquipement(choixArme, j1);  // ID correspondant à l'arme choisie

    // Affichage de l'équipement du joueur 1
    cout << "Votre équipement a été appliqué avec succès." << endl;

    // Initialisation du compteur de tours
    int tour = 1;

    // Boucle de combat
    while (j1->getPV() > 0 && j2->getPV() > 0) {
        cout << "\n--- Tour " << tour << " ---\n";  // Affiche le numéro du tour

        int choix;
        int degats = 0;

        // Tour de Joueur 1 : Affichage des attaques en fonction du personnage
        cout << "\n";
        cout << "Joueur 1 (PV: " << j1->getPV() << ") à votre tour:" << endl;

        // Choisir les attaques du joueur en fonction du personnage
        if (j1 == &p1) {
            // Attaques de Snowqueen
            cout << "1. Frappe Préventive" << endl;
            cout << "2. Blast" << endl;
            cout << "3. Javelot de glace" << endl;
            cout << "4. Vent glaciale" << endl;
            cout << "5. Let it go" << endl;
        } else if (j1 == &p2) {
            // Attaques de Berserker
            cout << "1. Frappe Préventive" << endl;
            cout << "2. Blast" << endl;
            cout << "3. Frappe Punitive" << endl;
            cout << "4. Coup Déchaîné" << endl;
            cout << "5. Mouvement Alpha" << endl;
        }

        bool attaqueReussie = false;

        while (!attaqueReussie) {
            cout << "Entrez votre choix: ";
            cin >> choix;
            cout << "\n";

            switch (choix) {
                case 1:
                    degats = j1->frappe_preventive();
                    break;
                case 2:
                    degats = j1->blast();
                    break;
                case 3:
                    if (j1 == &p1) { // Snowqueen
                        degats = p1.Javelot_de_glace();
                    } else {  // Berserker
                        degats = p2.Frappe_punitive();
                    }
                    break;
                case 4:
                    if (j1 == &p1) { // Snowqueen
                        degats = p1.Vent_glaciale();
                    } else {  // Berserker
                        degats = p2.Coup_dechaine();
                    }
                    break;
                case 5:
                    if (j1 == &p1) { // Snowqueen
                        degats = p1.LetItGo();
                    } else {  // Berserker
                        degats = p2.Movement_Alpha();
                    }
                    break;
                default:
                    cout << "Choix non valide. Veuillez réessayer." << endl;
                    continue;
            }

            attaqueReussie = true;
        }

        j2->degat_recu(degats);
        if (j2->getPV() <= 0) {
            cout << "Joueur 2 est KO. Joueur 1 gagne!" << endl;
            break;
        }

        // Tour de Joueur 2 : Processus similaire
        cout << "\n";
        cout << "Joueur 2 (PV: " << j2->getPV() << ") à votre tour:" << endl;

        // Choisir les attaques du joueur en fonction du personnage
        if (j2 == &p1) {
            // Attaques de Snowqueen
            cout << "1. Frappe Préventive" << endl;
            cout << "2. Blast" << endl;
            cout << "3. Javelot de glace" << endl;
            cout << "4. Vent glaciale" << endl;
            cout << "5. Let it go" << endl;
        } else if (j2 == &p2) {
            // Attaques de Berserker
            cout << "1. Frappe Préventive" << endl;
            cout << "2. Blast" << endl;
            cout << "3. Frappe Punitive" << endl;
            cout << "4. Coup Déchaîné" << endl;
            cout << "5. Mouvement Alpha" << endl;
        }

        attaqueReussie = false;

        while (!attaqueReussie) {
            cout << "Entrez votre choix: ";
            cin >> choix;
            cout << "\n";

            switch (choix) {
                case 1:
                    degats = j2->frappe_preventive();
                    break;
                case 2:
                    degats = j2->blast();
                    break;
                case 3:
                    if (j2 == &p2) { // Berserker
                        degats = p2.Frappe_punitive();
                    } else {
                        degats = p1.Javelot_de_glace();
                    }
                    break;
                case 4:
                    if (j2 == &p2) { // Berserker
                        degats = p2.Coup_dechaine();
                    } else {
                        degats = p1.Vent_glaciale();
                    }
                    break;
                case 5:
                    if (j2 == &p2) { // Berserker
                        degats = p2.Movement_Alpha();
                    } else {
                        degats = p1.LetItGo();
                    }
                    break;
                default:
                    cout << "Choix non valide. Veuillez réessayer." << endl;
                    continue;
            }

            attaqueReussie = true;
        }

        j1->degat_recu(degats);
        if (j1->getPV() <= 0) {
            cout << "Joueur 1 est KO. Joueur 2 gagne!" << endl;
            break;
        }

        // Incrémenter le compteur de tours
        tour++;
    }

    delete con; // Libération de la connexion
    return 0;
}

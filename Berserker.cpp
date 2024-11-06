#include "Berserker.h"
Berserker::Berserker() : personnage_de_base(5000, 400, 250, 110, 0) {
}
Berserker::Berserker(int pv, int attaque, int defense, int speed, int energie)
    : personnage_de_base(pv, attaque, defense, speed, energie) {
}

int Berserker::Frappe_punitive() {
    cout << "Vous utilisez Frappe Punitive" << endl;
    int pv_max = 5000;
    int degats = pv_max * 0.3; // Inflige 30% des PV max
    int cout_pv = pv_max * 0.1; // Consomme 10% des PV max
    
    if (pv > cout_pv) {
        pv -= cout_pv;
    } else {
        pv = 0;
    }
    
    energie += 20;
    if (energie > 100) {
        energie = 100;
    }
    
    cout << "Cela fait " << degats << " de dégâts" << endl;
    cout << "Vous consommez " << cout_pv << " points de vie" << endl;
    cout << "Vous gagnez 20 points d'énergie. Vous avez maintenant " << energie << " points d'énergie" << endl;
    cout << "Il vous reste " << pv << " points de vie" << endl;
    cout << "\n";
    return degats;
}

int Berserker::Coup_dechaine() {
    cout << "Vous utilisez Coup Déchaîné" << endl;
    int pv_max = 5000;
    int degats = pv_max * 0.5; // Inflige 50% des PV max
    int cout_pv = pv_max * 0.15; // Consomme 15% des PV max
    
    if (pv > cout_pv) {
        pv -= cout_pv;
    } else {
        pv = 0;
    }
    
    energie += 30;
    if (energie > 100) {
        energie = 100;
    }
    
    cout << "Cela fait " << degats << " de dégâts" << endl;
    cout << "Vous consommez " << cout_pv << " points de vie" << endl;
    cout << "Vous gagnez 30 points d'énergie. Vous avez maintenant " << energie << " points d'énergie" << endl;
    cout << "Il vous reste " << pv << " points de vie" << endl;
    return degats;
}


int Berserker::Movement_Alpha() {
    if (energie == 100) {
        cout << "Vous utilisez Mouvement Alpha" << endl;
        int pv_max = 5000;
        // Dégâts basés sur 75% des PV actuels
        int degats = pv_max * 0.75; 
        cout << "Cela fait " << degats << " de dégâts" << endl;
        
        // Régénère 50% des PV actuels
        pv += pv_max * 0.5;
        if (pv > pv) {  // Assure que les PV n'excèdent pas le maximum
            pv = pv;
        }
        
        cout << "Vous régénérez 50% de vos points de vie. Il vous reste maintenant " << pv << " points de vie" << endl;
        
        // Consomme toute l'énergie
        energie = 0;
        cout << "Vous consommez toute votre énergie et avez maintenant " << energie << " points d'énergie" << endl;
        
        return degats;
    } else {
        cout << "Vous n'avez pas assez d'énergie pour utiliser cette attaque" << endl;
        cout << "Il vous manque " << 100 - energie << " points d'énergie" << endl;
        cout << "Faites une autre attaque" << endl;
        return 0;
    }
}

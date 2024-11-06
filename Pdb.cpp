#include "Pdb.h"
personnage_de_base::personnage_de_base() : pv(4500),attaque(400),defense(120),speed(98),energie(0)
{}
personnage_de_base::personnage_de_base(int pv,int attaque,int defense,int speed,int energie)
    : pv(pv),attaque(attaque),defense(defense),speed(speed),energie(energie){}

int personnage_de_base::frappe_preventive() {
    cout << "Vous utilisez Frappe préventive"<< endl;
    int degats = attaque;
    cout << "Cela fait " << attaque << " de dégâts" << endl; 
    energie += 10;
    if (energie > 100) {
        energie = 100; 
    }
    cout << "Vous gagnez " << 10 << " d'énergie" << endl;
    cout << "Vous avez " << energie << " d'énergie" << endl;
    return degats;
}

int personnage_de_base::blast() {
    cout << "Vous utilisez Blast" << endl;
    int degats = attaque * 1.5; 
    cout << "Cela fait " << degats << " de dégâts" << endl;
    energie += 15;
    if (energie > 100) {
        energie = 100; 
    }
    cout << "Vous gagnez " << 15 << " d'énergie" << endl;
    cout << "Vous avez " << energie << " d'énergie" << endl;
    return degats;
}

int personnage_de_base::attaque_delta() {
    if (energie == 100) { 
        cout << "Vous utilisez Attaque Delta" << endl;
        int degats = attaque * 3.5;  
        cout << "Cela fait " << degats << " de dégâts" << endl;
        energie = 0;
        cout << "Vous n'avez plus d'énergie" << endl;
        return degats;  
    } else {
        cout << "Vous n'avez pas assez d'énergie pour utiliser cette attaque" << endl;
        cout << "Il vous manque " << 100 - energie << " d'énergie" << endl;
        cout << "Faites une autre attaque" << endl;
        return 0;
    }   
}

void personnage_de_base::degat_recu(int degats) {
    int degats_infliges = degats - defense; 
    if (degats_infliges < 0) {
        degats_infliges = 0; // degats ne peuvent pas etre negatif
    }
    
    pv -= degats_infliges;
    if (pv < 0) {
        pv = 0; // pv ne peuvent pas etre negatif
    }
    
    cout << "Vous recevez " << degats_infliges << " de dégâts, il vous reste " << pv << " points de vie." << endl;
}
void personnage_de_base::setEquipement(const string& heaume, const string& gilet, const string& gants, const string& bottes) {
    cout << "Équipement du personnage : " << endl;
    cout << "Heaume: " << heaume << endl;
    cout << "Gilet: " << gilet << endl;
    cout << "Gants: " << gants << endl;
    cout << "Bottes: " << bottes << endl;
}

void personnage_de_base::setEquipementArme(const string& arme) {
    cout << "L'arme équipée est : " << arme << endl;
}


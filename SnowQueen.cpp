#include "Snowqueen.h"

Snowqueen::Snowqueen() : personnage_de_base(8520,500,200,121,0)
{}
Snowqueen::Snowqueen(int pv, int attaque, int defense, int speed, int energie)
    : personnage_de_base(pv,attaque,defense,speed,energie){}


int Snowqueen::Javelot_de_glace() {
    cout << "Vous utilisez Javelot de glace" << endl;
    int degats = attaque * 1.25;
    cout << "Cela fait " << degats << " de dégâts" << endl; 
    energie += 20;
    if (energie > 100) {
        energie = 100; 
    }
    cout << "Vous gagnez " << 20 << " d'énergie" << endl;
    cout << "Vous avez " << energie << " d'énergie" << endl;
    return degats;
}

int Snowqueen::Vent_glaciale() {
    cout << "Vous utilisez Vent Glaciale" << endl;
    int degats = attaque * 1.5; 
    cout << "Cela fait " << degats << " de dégâts" << endl;
    energie += 30;
    if (energie > 100) {
        energie = 100; 
    }
    cout << "Vous gagnez " << 30 << " d'énergie" << endl;
    cout << "Vous avez " << energie << " d'énergie" << endl;
    return degats;
}

int Snowqueen::LetItGo() {
    if (energie == 100) { 
        cout << "Vous utilisez Let It Go" << endl;
        int degats = attaque * 1.75;   
        energie = 0;
        cout << "Cela fait " << degats << " de dégâts" << endl;
        cout << "Vous n'avez plus d'énergie" << endl;
        return degats;
         
    } else {
        cout << "Vous n'avez pas assez d'énergie pour utiliser cette attaque" << endl;
        cout << "Il vous manque " << 100 - energie << " d'énergie" << endl;
        cout << "Faites une autre attaque" << endl;
        return 0;  
    }   
}


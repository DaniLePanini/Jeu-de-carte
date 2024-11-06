#include <iostream> 
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <mysql/mysql.h>
#include <cppconn/resultset.h>
using namespace std;

class personnage_de_base {
    protected:
    int pv;
    int attaque;
    int defense;
    int speed;
    int energie;
    public:
    // Constructeurs
    personnage_de_base();
    personnage_de_base(int pv,int attaque,int defense,int speed,int energie);
    // Méthodes virtuelles pour les classes qui vont heriter
    virtual int frappe_preventive();
    virtual int blast();
    int attaque_delta();
    virtual void degat_recu(int degats);
    virtual void setEquipement(const string& heaume, const string& gilet, const string& gants, const string& bottes);
    virtual void setEquipementArme(const string& arme);  // Pour l'arme spécifique

    int getSpeed() const { return speed; }
    int getPV() const { return pv; }
    // Méthodes d'ajout de bonus aux caractéristiques du personnage
    void ajouterPV(int bonus) { pv += bonus; }
    void ajouterAttaque(int bonus) { attaque += bonus; }
    void ajouterDefense(int bonus) { defense += bonus; }
    void ajouterVitesse(int bonus) { speed += bonus; }
};

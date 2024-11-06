#include "Snowqueen.h"

class  Berserker : public personnage_de_base
{
    public:
    Berserker();
    Berserker(int pv,int attaque,int defense,int speed,int energie);
    int Frappe_punitive();
    int Coup_dechaine();
    int Movement_Alpha();
};
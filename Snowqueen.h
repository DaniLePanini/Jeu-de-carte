#include "Pdb.h"

class  Snowqueen : public personnage_de_base
{
    public:
    Snowqueen();
    Snowqueen(int pv,int attaque,int defense,int speed,int energie);

    int Javelot_de_glace();
    int Vent_glaciale();
    int LetItGo();

};
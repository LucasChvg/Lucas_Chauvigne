#ifndef DONJON_H
#define DONJON_H
#include <iostream>
#include "personnage.h"
#include <string>

class Donjon
{
    public:
        Donjon(Personnage *perso, int niveau);
        virtual ~Donjon();
        void Combat(Personnage *perso, Personnage *enemy);




    protected:

        int alea;
        int d_choix;
        int d_degat;

    private:
};

#endif // DONJON_H

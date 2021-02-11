#ifndef INVENTAIRE_H
#define INVENTAIRE_H


#include "equipement.h"
#include "inventaire.h"
#include <iostream>
#include <list>
#include <string>

class Inventaire
{
    public:
        std::list<Equipement *> epe;
        std::list<Equipement *> epeMarchand;
        Inventaire();
        Inventaire(int classType);
        virtual ~Inventaire();
        void AfficherInventaire();
        void ChangerEpe();
        void Boutique();
        int m_or = 50;

        int Getmnpotion() { return m_npotion; }
        void Setmnpotion(int val) { m_npotion = val; }
        //Equipement Armure("Armure De cuir",0,12,true);

    protected:
        int m_npotion = 0;

    private:
};

#endif // INVENTAIRE_H

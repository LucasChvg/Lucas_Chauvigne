#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>
#include <list>
#include <string>

#include "personnage.h"
#include "equipement.h"
#include "inventaire.h"
#include "marchand.h"




using namespace std;

class Personnage
{
    public:
        Personnage();

        virtual ~Personnage();

        float Getpv() { return m_pv; }
        void Setpv(float val) { m_pv = val; }

        int Getmdegat() { return m_degat; }
        void Setmdegat(int val) { m_degat = val; }

        Inventaire *m_inv;
       // Marchand *m_marchand;

        void AfficherStat();

        int niveau=1;


    protected:

        float m_pv;
        string m_catchphrase;
        string m_nom;
        int m_degat=4;



    private:
};

#endif // PERSONNAGE_H

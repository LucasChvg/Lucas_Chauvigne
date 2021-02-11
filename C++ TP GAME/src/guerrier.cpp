#include "guerrier.h"

using namespace std;

Guerrier::Guerrier()
{
    this->m_pv=100;
    //this->m_catchphrase="C'est l'heure du Combat !";
}

Guerrier::~Guerrier()
{
    //dtor
}
Guerrier::Guerrier(string nom)
{
    this->m_nom = nom;
    this->m_pv=300;
    this->m_catchphrase="Preparez vous a ma venu, ce monde va bientot changer !";
    //Inventaire m_inv(1);
}

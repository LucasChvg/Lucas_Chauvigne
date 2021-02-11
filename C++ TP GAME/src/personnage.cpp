#include <iostream>
#include "personnage.h"
#include <string>

using namespace std;



Personnage::Personnage()
{
    this->m_inv = new Inventaire(1);
    //this->m_marchand = new Marchand();

    cout << "CREATION" << endl;
}

Personnage::~Personnage()
{
    delete this->m_inv;
}
void Personnage::AfficherStat()
{
    cout << "PV restant : " << m_pv << endl;
    cout << m_catchphrase << "\n" <<endl;

}



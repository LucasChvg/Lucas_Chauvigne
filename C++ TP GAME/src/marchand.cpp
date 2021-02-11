#include "marchand.h"

#include <iostream>
#include <string>

using namespace std;

Marchand::Marchand()
{
    std::list<Equipement>::iterator it;
    Equipement *arme2 = new Equipement("Grande Hache", 15, 0, true, false, 50, 25);
    Equipement *arme = new Equipement("Epe Divine", 30, 0, true, true, 100, 50);



    this->epeMarchand.push_back(arme);
    this->epeMarchand.push_back(arme2);
//    cout << "Arme : " << this->epe.front().GetnomE() << endl;
    cout << "MARCHAND FONCTIONNE" << endl;
    cout << this->epeMarchand.size() << endl;
}

Marchand::~Marchand()
{


}


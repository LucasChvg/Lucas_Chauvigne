#include "equipement.h"
#include "inventaire.h"

#include <iostream>
#include <string>

using namespace std;

Equipement::Equipement()
{

}

Equipement::~Equipement()
{
    //dtor
}
Equipement::Equipement(string nom, int attaque, int defense, bool possede, bool estEquipe, int m_prix, int m_prixVente)
{
    this->m_nomE = nom;
    this->m_degat = attaque;
    this->m_defense = defense;
    this->possede = possede;
    this->estEquipe = estEquipe;
    this->m_prix=m_prix;
    this->m_prixVente=m_prixVente;
}
void Equipement::AfficherEquipement()
{
    //for(int i=0; i<20; i++){
    //    if(epe[i].possede == true){
            cout << "Arme : " << this->m_nomE << endl;
            cout << "Degat : " << this->m_degat <<endl;
            if(this->estEquipe == true){
                    cout << "Equipe !" << endl;
            }
    //    }
    //}
}


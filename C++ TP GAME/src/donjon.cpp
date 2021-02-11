#include <iostream>
#include <list>
#include <string>
#include "donjon.h"
#include "personnage.h"
#include "equipement.h"
#include "inventaire.h"
#include "guerrier.h"
#include<bits/stdc++.h>

using namespace std;

Donjon::Donjon(Personnage *perso, int niveau)
{
    for(int j = 1; j<=floor(niveau*1.5); j++){

        Guerrier *Ennemie = new Guerrier();

        Ennemie->Setpv(35*0.7*niveau);
        Ennemie->AfficherStat();
        Ennemie->Setmdegat(10);
        this->Combat(perso, Ennemie);
        delete Ennemie;
        break;
    }
}

Donjon::~Donjon()
{
    //dtor
}

void Donjon::Combat(Personnage *perso, Personnage *enemy)
{
    cout << "===================================================\n" << endl;
    cout << "Vous etes entre en combat avec un guerrier ennemie !\n\n" <<endl;
    while(enemy->Getpv()>0 && perso->Getpv() > 0){
        cout << "====================================================================================================" << endl;
        cout << "Que faire ? (1) Attaquer (2) inventaire" << endl;
        cout << "====================================================================================================\n" << endl;
        cin >> d_choix;
        switch(d_choix){
        case 1 :
            {
            cout << "Vous Attaquez !" << endl;

            std::list<Equipement*>::iterator it;

            for (it = perso->m_inv->epe.begin(); it != perso->m_inv->epe.end(); ++it) {
                if((*it)->estEquipe == true){
                    d_degat=(*it)->Getdegat()+perso->Getmdegat();
                    cout << "Degat inflige : " << d_degat << endl;
                    enemy->Setpv(enemy->Getpv()-d_degat);
                    enemy->AfficherStat();
                }
            }

            break;
            }
        case 2 :
            {
            int choixInv = 0;
            while(choixInv!=3){
            cout << "====================================================================================\n" << endl;
            cout << "INVENTAIRE : (1) Utiliser potion de soin, (2) Changer arme, (3) Quitter l'inventaire" <<endl;
            cout << "====================================================================================\n" << endl;
            perso->AfficherStat();
            perso->m_inv->AfficherInventaire();
            cout<< "niveau actuel : " << perso->niveau <<endl;
            cin >> choixInv;
            switch(choixInv){
            case 1 :
                {
                if(perso->m_inv->Getmnpotion()>0){
                    perso->Setpv(perso->Getpv()+50);
                    perso->m_inv->Setmnpotion(perso->m_inv->Getmnpotion()-1);
                }else{
                    cout << "vous n'avez pas de potion !" << endl;
                }

                break;
                }
            case 2 :
                perso->m_inv->ChangerEpe();
                break;
            }
            }


            break;
            }


            }
        perso->Setpv(perso->Getpv()-enemy->Getmdegat());
        cout << "l'ennemie vous attaque et vous inflige "<< enemy->Getmdegat() << " de degat !" << endl;
        perso->AfficherStat();

        }
        if(enemy->Getpv()<=0){
            cout << "====================================" << endl;
            cout << "Vous avez gagnez le combat ! Bravo !" << endl;
            cout << "or gagne : " << perso->niveau*6 << " ! " << endl;
            cout << "Vous avez gagne une potion de soin ! " << endl;
            cout << "====================================" << endl;
            perso->m_inv->m_or = perso->m_inv->m_or + perso->niveau*6;
            perso->m_inv->Setmnpotion(perso->m_inv->Getmnpotion()+1);
            perso->niveau++;

        }
        if(perso->Getpv()<=0){
            cout << "==============================================" << endl;
            cout << "Aie ! vous avez echoue, vous fuyez le donjon !" << endl;
            cout << "==============================================" << endl;
    }

}

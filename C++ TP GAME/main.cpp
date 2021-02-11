#include <iostream>
#include <string>
#include<bits/stdc++.h>

#include "equipement.h"
#include "guerrier.h"
#include "inventaire.h"
#include "personnage.h"
#include "donjon.h"
#include "marchand.h"

using namespace std;

//bool first = true;

int main()
{
    string name;
    int choix;
    int choixInv;
    //int niveau = 1;
    int classPerso;
    cout << "Bienvenue dans le monde de Yufiloquitanumorito ! Dis-moi, quel est ton nom ?" << endl;
    cin >> name;
    cout << "tres bien " << name << " ! Dis moi, de classe es-tu ?" << endl;
    cout << "Tu as le choix entre Guerrier (1), Pretre (2) ou mage (3)\nDis moi donc le numero correspondant a ta classe !" << endl;
    cin >> classPerso;
    Guerrier perso(name);
    //Marchand Marchand();


    if(classPerso==1){

        cout << "Nous sommes heureux de ta venu jeune Guerrier !\n" << endl;
        cout << "===============================================\n" << endl;
        perso.AfficherStat();
        cout << "===============================================" << endl;
        cout << "Il est temps pour toi de commencer cette aventure !" << endl;
        cout << "===============================================\n" << endl;
        perso.m_inv->AfficherInventaire();
        cout<< "niveau actuel : " << perso.niveau <<endl;
    }

    while(choix!=9){
        cout << "====================================================================================================" << endl;
        cout << "Que faire ? (1) Commencer un nouveau donjon, (2) aller voir le marchand, (3) regarder l'inventaire, (9) Quitter le jeu :" << endl;
        cout << "====================================================================================================\n" << endl;
        cin >> choix;
        choixInv = 0;
        switch(choix){
        case 1 :
            {
            cout << "===============================================" << endl;
            cout << "Voyage en direction du donjon niveau "<< floor(perso.niveau) << " ! " <<endl;
            cout << "===============================================\n" << endl;
            Donjon *MonDonjon = new Donjon(&perso, perso.niveau);
            //perso.m_inv->AfficherInventaire();

            break;
            }

        case 2 :
            cout << "========" << endl;
            cout << "MARCHAND" <<endl;
            cout << "========\n" << endl;
            perso.m_inv->Boutique();
            break;
        case 3 :
            while(choixInv!=3){
            cout << "====================================================================================\n" << endl;
            cout << "INVENTAIRE : (1) Utiliser potion de soin, (2) Changer arme, (3) Quitter l'inventaire" <<endl;
            cout << "====================================================================================\n" << endl;
            perso.AfficherStat();
            perso.m_inv->AfficherInventaire();
            cout<< "niveau actuel : " << perso.niveau <<endl;
            cin >> choixInv;
            switch(choixInv){
            case 1 :
                {
                perso.Setpv(perso.Getpv()+50);
                perso.m_inv->Setmnpotion(perso.m_inv->Getmnpotion()-1);
                break;
                }
            case 2 :
                perso.m_inv->ChangerEpe();
                break;
            }
            }


            break;

        }


    }

    return 0;
}

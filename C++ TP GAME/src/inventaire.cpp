#include "inventaire.h"
#include "equipement.h"

#include <iostream>
#include <string>

using namespace std;

Inventaire::Inventaire()
{

}

Inventaire::~Inventaire()
{
    //dtor
}
Inventaire::Inventaire(int classType)
{

    int classT = classType;
    std::list<Equipement>::iterator it;
    Equipement *arme = new Equipement("sabre", 8, 0, true, true, 0, 5);
    Equipement *arme2 = new Equipement("Epe Sanglante", 17, 0, true, false, 65, 30);

    this->epe.push_back(arme);
    this->epe.push_back(arme2);
//    cout << "Arme : " << this->epe.front().GetnomE() << endl;

    cout << this->epe.size() << endl;

    Equipement *arme3 = new Equipement("Grande Hache", 15, 0, true, false, 50, 25);
    Equipement *arme4 = new Equipement("Epe Divine", 30, 0, true, true, 100, 50);



    this->epeMarchand.push_back(arme3);
    this->epeMarchand.push_back(arme4);
//    cout << "Arme : " << this->epe.front().GetnomE() << endl;
    cout << "MARCHAND FONCTIONNE" << endl;
    cout << this->epeMarchand.size() << endl;

/*    epe[0].Setdegat(8);
    epe[0].Setdefense(0);
    epe[0].SetnomE("sabre");
    epe[0].possede = true;
    cout << "Arme : " << epe[0].GetnomE() << endl;
    epe[0].AfficherEquipement();

    this->epe[0] = arme1;*/
/*    epe[0].Setdegat(8);
    epe[0].Setdefense(0);
    epe[0].SetnomE("sabre");
    epe[0].possede = true;
    cout << "Arme : " << epe[0].GetnomE() << endl;
    epe[0].AfficherEquipement();*/
    //Equipement Armure("Armure De cuir",0,12,true);

}

void Inventaire::AfficherInventaire()
{
    std::list<Equipement*>::iterator it;

    //this->epe.front()->AfficherEquipement();

    //cout << this->epe.size() << endl;
    for (it = this->epe.begin(); it != this->epe.end(); ++it) {
        (*it)->AfficherEquipement();
        cout<<endl;
    }
    cout<< "Nombre de potions de soins : "<<this->m_npotion<<endl;
    cout<< "Or : "<<this->m_or<<endl;
}
void Inventaire::ChangerEpe()
{
    std::list<Equipement*>::iterator it;
    int compteur = 1;
    int choixEpe=2;
    for (it = this->epe.begin(); it != this->epe.end(); ++it) {

        cout<<"EPE " << compteur << " : "<<endl;
        (*it)->estEquipe = false;
        (*it)->AfficherEquipement();
        compteur++;
    }
    cout<<"Quelle Epe voulez vous equiper ? (entrer numero) :"<<endl;
    cin>>choixEpe;
    compteur=1;
    for (it = this->epe.begin(); it != this->epe.end(); ++it) {

    cout<<"EPE " << compteur << " : "<<endl;
    (*it)->AfficherEquipement();
    if(choixEpe==compteur){

        (*it)->estEquipe = true;
        (*it)->AfficherEquipement();

    }
    compteur++;
}
    //do{
   /* for (it = this->epe.begin(); it != this->epe.end(); ++it) {
        if(choixEpe==compteur){
            cout<<"EPE 1 : "<<endl;
            (*it)->estEquipe = true;
            (*it)->AfficherEquipement();
            compteur++;
        }

    }*/
    //}while(choixEpe!=compteur)

}
void Inventaire::Boutique()
{

    int ChoixBoutique = 0;
    while(ChoixBoutique != 9){
        cout << "=====================================" << endl;
        cout << "QUELLE BOUTIQUE VOULEZ VOUS VISITER ? (1) Potion, (2) Epe, (9) Sortir" << endl;
        cout << "=====================================\n" << endl;
        cin >> ChoixBoutique;
        switch(ChoixBoutique){
        case 1:
            {
            int nb = 0;
            cout<<"Entrer le nombre de potion a acheter ! (Prix de la potion : 20 or) :"<<endl;
            cin >> nb;
            if(this->m_or >= nb*20 && nb>0){           //si on a assez d'or
                this->m_or=this->m_or-(nb*20);   //on enleve l'or de l'inventaire
                this->m_npotion = this->m_npotion+nb;   //on rajoute les potions dans l'inventaire

            }else{
                cout << "vous n'avez pas assez d'or !" << endl;
            }
            break;
        }
        case 2 :
            {
                std::list<Equipement*>::iterator it;
                int compteur = 1;
                int choixAchat=2;
                for (it = this->epeMarchand.begin(); it != this->epeMarchand.end(); ++it) {

                    cout<<"EPE " << compteur << " : "<<endl;
                    (*it)->estEquipe = false;
                    (*it)->AfficherEquipement();
                    cout<<"PRIX : "<<(*it)->Getprix() <<"\n"<<endl;
                    compteur++;
                }
                cout<<"Quelle Epe voulez vous Acheter ? (entrer numero) :"<<endl;
                cin>>choixAchat;
                compteur=1;
                for (it = this->epeMarchand.begin(); it != this->epeMarchand.end(); ++it) {
                if(choixAchat==compteur){
                    if(this->m_or >= (*it)->Getprix()){           //si on a assez d'or
                        this->m_or=this->m_or-(*it)->Getprix();   //on enleve l'or de l'inventaire
                        Equipement *arme = new Equipement();
                        arme = (*it);
                        this->epe.push_back(arme);                //on rajoute l'arme dans l'inventaire

                    }else{
                        cout << "vous n'avez pas assez d'or !" << endl;
                    }

                }
                compteur++;
                }
            }
        }
    }
}

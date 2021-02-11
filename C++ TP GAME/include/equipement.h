#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <string>


using namespace std;

class Equipement
{
    public:
        Equipement();
        virtual ~Equipement();
        Equipement(string nom, int attaque, int defense, bool possede, bool estEquipe, int m_prix, int m_prixVente);

        bool possede;
        bool estEquipe;

        void AfficherEquipement();

        int GetprixVente() { return m_prixVente; }
        void SetprixVente(int val) { m_prixVente = val; }
        int Getprix() { return m_prix; }
        void Setprix(int val) { m_prix = val; }
        int Getdegat() { return m_degat; }
        void Setdegat(int val) { m_degat = val; }
        int Getdefense() { return m_defense; }
        void Setdefense(int val) { m_defense = val; }
        string GetnomE(){return m_nomE;}
        void SetnomE(string nom){m_nomE = nom;}

    protected:
        string m_nomE;
        int m_prixVente;
        int m_prix;
        int m_degat;
        int m_defense;


    private:
};

#endif // EQUIPEMENT_H

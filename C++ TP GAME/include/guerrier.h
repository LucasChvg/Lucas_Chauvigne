#ifndef GUERRIER_H
#define GUERRIER_H
#include <string>

#include <Personnage.h>


class Guerrier : public Personnage
{
    public:
        Guerrier();
        Guerrier(string nom);
        virtual ~Guerrier();
        Frapper(Personnage cible);

    protected:

    private:
};

#endif // GUERRIER_H

#ifndef MARCHAND_H
#define MARCHAND_H

#include <iostream>
#include <list>
#include <string>
#include<bits/stdc++.h>

#include "inventaire.h"
#include "equipement.h"

class Marchand
{
    public:
        Marchand();
        virtual ~Marchand();

        std::list<Equipement *> epeMarchand;

    protected:

    private:
};

#endif // MARCHAND_H

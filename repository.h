#pragma once
#include "entity.h"

class Repository
{
    private:
        Entity e[20];
        int n;
    public:
        Repository();
        ~Repository();

        void addElem(Entity s);
        Entity* getAll();
        int getSize();

};

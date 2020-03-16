#pragma once
#include <ostream>

using namespace std;

class Entity
{
    private:
        char* name;
    public:
        Entity();
        Entity(char* name);
        Entity(const Entity& s);
        ~Entity();

        char* getName();
        void setName(char* name);
        Entity& operator = (const Entity& s);
        bool operator == (const Entity& s);
        friend ostream& operator<<(ostream& os, const Entity& s);

};


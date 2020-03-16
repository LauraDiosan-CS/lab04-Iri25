#include <iostream>
#include "tests.h"
#include "entity.h"

using namespace std;

int main()
{
    char name[100];
    cout << "Dati numele: ";
    cin >> name;
    
    tests();
    Entity s1(name);
    cout << s1;

    Entity s2(s1);
    Entity s3 = s1;
    Entity s4;
    s4 = s2;
}


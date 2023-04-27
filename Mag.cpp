#include <iostream>
#include "Mag.h"

using namespace std;

Mag::Mag(string n, float hp)
{
    nazwa = n;
    zdrowie_max = hp;
};

void Mag::wyswietl()
{
    cout << nazwa << " HPmax: \t" << zdrowie_max << endl;
};

Statystyki::Statystyki(Mag &m, bool p, float hp, float dmg, float def)
{
    nazwa = m.nazwa;
    zdrowie_max = m.zdrowie_max;
    plec = p;
    zdrowie = hp;
    obrazenia = dmg;
    obrona = def;
};
void Statystyki::wyswietl()
{
    cout << "--------------------" << endl;
    cout << " ~~ " << nazwa << " ~~ " << endl;
    cout << "HP max: \t" << zdrowie_max << endl;
    cout << "Aktualne HP: \t" << zdrowie << endl;
    cout << "Obrazenia: \t" << obrazenia << endl;
    cout << "Pancerz: \t" << obrona << endl;
    cout << "--------------------" << endl;
}

void Statystyki::wypij_miksture()
{
    if (zdrowie <= zdrowie_max - 150)
    {
        zdrowie += 150;
        cout << "Uleczono!" << endl;
    }
    else
    {
        zdrowie = zdrowie_max;
        cout << "Uleczono do maksymalnej wartosci HP!";
    }
}

void Statystyki::medytuj()
{
    zdrowie = zdrowie_max;
    if (plec)
    {
        obrazenia += 5;
        cout << "Medytacja - uleczono i zwiekszono obrazenia o 5" << endl;
    }
    else
    {
        obrona += 5;
        cout << "Medytacja - uleczono i zwiekszono pancerz o 5" << endl;
    }
}
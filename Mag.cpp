#include <iostream>
#include "Mag.h"

using namespace std;

Mag::Mag(string n, float hp)
{
    nazwa = n;
    zdrowie_max = hp;
    zywy = true;
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

Statystyki::~Statystyki() 
{
        cout << nazwa << " juz nie wroci" << endl;
}
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

void Statystyki::czy_zyje()
{
    if (zdrowie <= 0) {
        zywy = false;
    }
    if (zywy = true) {
        cout << nazwa << " zyje! " << zdrowie << "/" << zdrowie_max << " HP" << endl;
    } else {
        cout << nazwa << " nie zyje! GAME OVER" << endl;
    }
}

void Statystyki::wypij_miksture()
{
    if (zdrowie <= zdrowie_max - 150)
    {
        zdrowie += 150;
        cout << nazwa <<" - Uleczono!" << endl;
    }
    else
    {
        zdrowie = zdrowie_max;
        cout << nazwa << " - Uleczono do maksymalnej wartosci HP!" << endl;
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

Wojownik::Wojownik(string n, float hp) {
    nazwa = n;
    zdrowie_max = hp;
    zywy = true;
}

void atakuj(Statystyki& a, Statystyki& s)
{   
    s.zdrowie = s.zdrowie - (a.obrazenia - (0.5 * s.obrona));
    cout << "Zaatakowano " << s.nazwa << " przez " << a.nazwa << endl;
    s.czy_zyje();
}

void ulecz(Statystyki& a, Statystyki& s)
{
     if (s.zdrowie <= s.zdrowie_max - 50)
    {
        s.zdrowie += 50;
        cout << a.nazwa <<" uleczyl/a " << s.nazwa << endl;
    }
    else
    {
        s.zdrowie = s.zdrowie_max;
        cout << a.nazwa <<" uleczyl/a " << s.nazwa << endl;
    }
};

void ultimate(Statystyki& a, Statystyki& s)
{
    cout << a.nazwa << " uzyl/a ultimate na: " << s.nazwa << endl;
    s.zdrowie = s.zdrowie - (a.obrazenia * 5);
    s.czy_zyje();
}
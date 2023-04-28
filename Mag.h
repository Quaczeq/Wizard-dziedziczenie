#include <iostream>
#include <vector>

using namespace std;

class Mag
{
public:
    string nazwa;
    float zdrowie_max;
    bool zywy;

    Mag(string n = "Wizard", float hp = 100);
    void wyswietl();
};

class Statystyki : public Mag
{
public:
    bool plec; // true - mezczyzna, false - kobieta
    float zdrowie, obrazenia, obrona;
    friend void atakuj(Statystyki &, Statystyki &);
    friend void ulecz(Statystyki &, Statystyki &);
    friend void ultimate(Statystyki &, Statystyki &);

    Statystyki(Mag &m, bool p = 0, float hp = 100, float dmg = 25, float def = 15);
    ~Statystyki();

    void czy_zyje();
    void wypij_miksture(); // odnawia 150 punktow zdrowia
    void medytuj();        // odnawia cale zdrowie. Dla mezczyzny daje +5 do ataku, kobiecie +5 do obrony
    void wyswietl();       // przykrywa funckje Mag::wyswietl() i rozszerza ja o statystyki
};

class Wojownik : public Mag
{
public:
    int sila;
    Wojownik(string n = "Warior", float hp = 300, int s = 2);
};

void atakuj(Statystyki &, Statystyki &);
void ulecz(Statystyki &, Statystyki &);
void ultimate(Statystyki &, Statystyki &);

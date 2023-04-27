#include<iostream>

using namespace std;

class Mag
{
public:
    string nazwa;
    float zdrowie_max;
    
    Mag(string n = "Wizard", float hp = 100);
    void wyswietl();
};

class Statystyki :public Mag
{
protected:
    bool plec; //true - mezczyzna, false - kobieta    
    float zdrowie, obrazenia, obrona;
public:
    Statystyki(Mag& m, bool p = 0, float hp = 100, float dmg = 25, float def = 15);
    void wypij_miksture(); //odnawia 150 punktow zdrowia
    void medytuj(); //odnawia cale zdrowie. Dla mezczyzny daje +5 do ataku, kobiecie +5 do obrony
    void wyswietl(); //przykrywa funckje Mag::wyswietl() i rozszerza ja o statystyki
};
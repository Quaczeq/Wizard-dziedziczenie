#include <iostream>
#include "Mag.h"

using namespace std;

int main()
{
    Mag m1("Stefan", 340); // Tworzymy maga
    m1.wyswietl();
    Statystyki s1(m1, true, 100, 35, 12); // Dodajemy staty: Mezczyzna, HP: 100, DMG: 35, DEF: 12
    s1.wyswietl();                        // Aktualne statystyki
    s1.medytuj();                         // Metoda leczy do maksymalnego poziomu zdrowia i dodaje +5 do obrazen lub obrony (zalezy od plci bohatera)
    s1.wyswietl();                        // Statystyki po medytacji

    return 0;
}
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

    Mag m2("Arietta", 535);
    Statystyki s2(m2, false, 535, 20, 34);
    s2.wyswietl();

    atakuj(s2,s1);
    atakuj(s2,s1);
    s1.wypij_miksture();
    atakuj(s1,s2);
    ultimate(s1,s2);
    s1.wyswietl();
    s2.wyswietl();
    
    Wojownik w1("Czesio", 830);
    w1.wyswietl();
    Statystyki s3(w1,true,600,60,70);
    s3.wyswietl();

    return 0;
}
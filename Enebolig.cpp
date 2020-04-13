/**
 *   @file      Enebolig.CPP
 *   @author    Gruppe 12, 2020
 */
#include "Bolig.h"
#include "Enebolig.h"
#include "LesData3.h"
#include <iostream>
#include <string>

/**
*initialiserer egne datamedlemmer
*/
Enebolig::Enebolig(const int nr) : Bolig(nr) {
    areal = 0; festetomt = false;
    boligType = enebolig;
}

/**
 *  leser inn egne data fra brukern/tastatur
 *  @see    Bolig::lesData()
 */
void Enebolig::lesData() {
    Bolig::lesData();
    areal = lesInt("Areal:\t", 1, 100);
    festetomt = (lesChar("\tFestetomt?  (j/N)") == 'J');
}
/**
 * Skriver egne data til skjerm
 *  @see    Bolig::skrivData()...
 */
void Enebolig::skrivData() {
    Bolig::skrivData();
    std::cout << "Areal:\t" << areal << '\n';
    if (festetomt)
    {
        std::cout << "Tomten er:\t" << " ei festetom" << '\n';
    }
    else { std::cout << "Tomten er:\t" << " selveiet" << '\n'; }
}
/**
 * Skriver egne data til fil
 *  @see    Bolig::skrivTilFil(...)
 */
void Enebolig::skrivTilFil(std::ofstream& ut) {
    Bolig::skrivTilFil(ut);
    ut << areal << ' ' << festetomt << '\n';
}

Enebolig::~Enebolig()
{
}

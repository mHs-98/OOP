/**
 *   @file      Enebolig.CPP
 *   @author    Gruppe 12
 */
#include "Bolig.h"
#include "Enebolig.h"
#include "LesData3.h"
#include <iostream>
#include <string>

Enebolig::Enebolig(const int nr) : Bolig(nr) {
    areal = 0; festetomt = false;
    boligType = enebolig;
}

/**
 *  
 *  @see    Bolig::lesData()
 */
void Enebolig::lesData() {
    Bolig::lesData();
    areal = lesInt("Areal:\t", 1, 100);
    festetomt = (lesChar("\tFestetomt?  (j/N)") == 'J');
}
/**
 *
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
 *
 *  @see    Bolig::skrivTilFil(...)
 */
void Enebolig::skrivTilFil(std::ofstream& ut) {
    Bolig::skrivTilFil(ut);
    ut << areal << ' ' << festetomt << '\n';
}

Enebolig::~Enebolig()
{
}

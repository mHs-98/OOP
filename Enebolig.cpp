/**
 *   @file      BOLIG.CPP
 *   @author    Abdisalan M. Hussein
 */
#include "Bolig.h"
#include "Enebolig.h"
#include "LesData3.h"
#include <iostream>

Enebolig::Enebolig(const int nr) : Bolig(nr) {
    areal = 0; festetomt = false;
}

void Enebolig::lesData() {
    Bolig::lesData();
    areal = lesInt("Areal:\t", 1, 100);
    festetomt = (lesChar("\tFestetomt?  (j/N)") == 'J');
}
void Enebolig::skrivData() {
   // Bolig::skrivData();
    std::cout << "Areal:\t" << areal << '\n';
    if (festetomt)
    {
        std::cout << "Tomten er:\t" << " ei festetom" << '\n';
    }
    else { std::cout << "Tomten er:\t" << " selveiet" << '\n'; }
}

void Enebolig::skrivTilFil(std::ofstream& ut) {
    ut << areal << ' ' << festetomt << '\n';
}

Enebolig::~Enebolig()
{
}

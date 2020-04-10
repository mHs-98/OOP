/**
 *   @file      Bolig.cpp
 *   @author    Gruppe 12, NTNU
 */

#include "Bolig.h"
#include "Enebolig.h"
#include "LesData3.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * Intialerer Enebolig innhold
 */ 
Enebolig::Enebolig(const int nr) : Bolig(nr) {
    areal = 0; festetomt = false;
}

/**
 * Leser enebolig sin data fra bruker
 * 
 * @see Bolig::lesData()
 */ 
void Enebolig::lesData() {
    Bolig::lesData();
    areal = lesInt("Areal:\t", 1, 100);
    festetomt = (lesChar("\tFestetomt?  (j/N)") == 'J');
}

/**
 * Skriver enebolig sin data
 */ 
void Enebolig::skrivData() {
   // Bolig::skrivData();
    std::cout << "Areal:\t" << areal << '\n';
    if (festetomt)
    {
        std::cout << "Tomten er:\t" << " ei festetom" << '\n';
    }
    else { std::cout << "Tomten er:\t" << " selveiet" << '\n'; }
}

/**
 * Skriver enebolig sin data ut til filen
 * 
 * @param   ut - ofstream referanse variable for å skrive til fil
 * @file    'SONER.DTA'
 */ 
void Enebolig::skrivTilFil(ofstream& ut) {
    ut << areal << ' ' << festetomt << '\n';
}

Enebolig::~Enebolig()
{
}

/**
*Sone.h, deklerasjonsklassen
*@author: Abdisalan M. Husein, Mahamed Hassan Said, Elias Touil, NTNU Gj�vik
*@file: Sone.h.
*
*/


#pragma once

#ifndef __SONE_H                  //  Ensures that this file will be
#define __SONE_H                  //  included only ONCE in each file

#include <iostream>
#include <fstream>
#include <vector>
#include "LesData3.h"
#include "Bolig.h"
#include <string>

//.extern class Bolig;
class Sone {
private:
    int unikSNr;                  /// Unik sonenummer
    std::string soneBeskrivelse;       /// Kort beskrivelse av sonen
    std::vector <Bolig*> gBoliger;     /// Alle boligene til salgs i sonen

public:
    Sone(); //unikSnr telles fra 1
    Sone(int nr);
    Sone(int snr, std::ifstream & in);
    void lesBeskrivelse();
    void skrivData();
    void skrivTilFil(std::ofstream & ut) ;
    void skrivEnSone(const int sNr);
    int finn(const std::string nvn);
    int hentSoneNr() {
        return unikSNr;}
    void lagnyOppdrag(int nr);
    void enOppdrag(int nr);
    void enkundeoversikt(std::ofstream& ut);
    void hjelpeKA();
    void slettEnOppdrag(int nr);



   


   

};

#endif


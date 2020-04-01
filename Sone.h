#pragma once

#ifndef __SONE_H                  //  Ensures that this file will be
#define __SONE_H                  //  included only ONCE in each file

#include <iostream>
#include <fstream>
#include <vector>
#include "LesData3.h"
#include "Bolig.h"

//.extern class Bolig;
class Sone {
private:
    int unikSNr;                  /// Unik sonenummer
    std::string soneBeskrivelse;       /// Kort beskrivelse av sonen
    std::vector <Bolig*> gBoliger;     /// Alle boligene til salgs i sonen

public:
    Sone(); //unikSnr telles fra 1
    Sone(int nr);
    void skrivTilFil();
    void lesFraFil();
    void lesBeskrivelse();
    void skrivData();
    void skrivEnSone(const int sNr);
    int finn(const std::string nvn);
    int hentSoneNr() {
        return unikSNr;}
    void lagnyOppdrag(int nr);
   

};

#endif


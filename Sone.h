#pragma once

#ifndef __SONE_H                  //  Ensures that this file will be
#define __SONE_H                  //  included only ONCE in each file

#include <iostream>
#include <fstream>
#include <vector>
#include "LesData3.h"


class Bolig;

class Sone {
private:
    int unikSNr;                  /// Unik sonenummer
    std::string soneBeskrivelse;       /// Kort beskrivelse av sonen
    std::vector <Bolig*> gBoliger;     /// Alle boligene til salgs i sonen

public:
    Sone() { unikSNr = 0; soneBeskrivelse = "Eksempel Beskrivelse"; } //unikSnr telles fra 1
    Sone() {unikSNr = 1; soneBeskrivelse = "Eksempel Beskrivelse";}
    void skrivTilFil();
    void lesFraFil();
    void lesBeskrivelse();
    void skrivData();
    void skrivEnSone(const int sNr);
    int finn(const std::string nvn);
    int hentSoneNr() {
        return unikSNr;
    }

};

#endif


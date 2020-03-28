#pragma once
#ifndef __SONE_H                  //  Ensures that this file will be
#define __SONE_H                  //  included only ONCE in each file

#include <iostream>
#include <fstream>
#include <vector>
#include "LesData3.h"

using namespace std;


class Bolig;

class Sone {
private:
    int unikSNr;                  /// Unik sonenummer
    string soneBeskrivelse;       /// Kort beskrivelse av sonen
    vector <Bolig*> gBoliger;     /// Alle boligene til salgs i sonen

public:

   /// Andre funskjoner
    void skrivTilFil();
    void lesFraFil();
    void lesBeskrivelse();
    void skrivData();
    int finn(const string nvn);
    int hentSoneNr() {
        return unikSNr;
    }
};

#endif
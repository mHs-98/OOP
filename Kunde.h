#pragma once

#ifndef __KUNDE_H                  //  Ensures that this file will be
#define __KUNDE_H                  //  Included only ONCE in each file.

#include "LesData3.h"
#include "enum.h"
#include "conster.h"
#include <fstream>

using namespace std;


class Kunde {

private:
     int kNr,           /// Unik kundenummer og skal sorteres på
         tlf;           ///
    string navn,        /// Kunde navn
            gate,       /// Gateaddresse(gate + nr)
            poststed,   /// (postnr + sted)
            mail;           /// Mail til vedkommende
    boligtype type;         /// 'Leilighet' eller 'Enebolig' -kundens interesse

public:
    Kunde();            /// Default constructor
    Kunde(int nr);       /// Copy constructor
    Kunde(ifstream &inn, int nr);
    ~Kunde();               /// Destructor
   /// Andre funskjoner
    void skrivTilFil();
    void lesFraFil();
    void lesData();
    void skrivData();
    int finn(const string nvn);

};

#endif

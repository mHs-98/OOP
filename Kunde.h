#pragma once

#ifndef __KUNDE_H                  //  Ensures that this file will be
#define __KUNDE_H                  //    included only ONCE in each file.
#include "LesData3.h"
#include "enum.h"
#include "conster.h"
#include <fstream>
using namespace std;


class Kunde {

private:
     int kNr,           ///unike kundenummer og skal sorteres på
         tlf;       ///
    string navn,        ///kunde navn
            gate,       ///gateaddresse(gate + nr)
            poststed,   /// (postnr + sted)
            mail;           /// mail til vedkommende
    boligtype type;         /// 'Leilighet' eller 'Enebolig' -kundens interesse

public:
    Kunde();            ///default constructor
    Kunde(int nr);       ///copy constructor
    Kunde(ifstream &inn, int nr);
    ~Kunde();               ///destructor
   ///andre funskjoner
    void skrivTilFil();
    void lesFraFil();
    void lesData();
    void skrivData();
    int finn(const string nvn);

};
#endif

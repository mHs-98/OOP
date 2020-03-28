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
<<<<<<< HEAD
    ~Kunde();               /// Destructor
   /// Andre funskjoner
    void skrivTilFil();
=======
    ~Kunde();               ///destructor
   ///andre funskjoner
    void skrivTilFil(ofstream& utfil);
>>>>>>> 1607d9ed823426741582d30f156b5d4526d550f2
    void lesFraFil();
    void lesData();
    void skrivData();
    int hentID();
   string hentNavn();
   

};

#endif

#pragma once

#ifndef __KUNDE_H                  //  Ensures that this file will be
#define __KUNDE_H                  //  Included only ONCE in each file.

#include "LesData3.h"
#include "enum.h"
#include "conster.h"
#include <fstream>
<<<<<<< HEAD
#include<vector>
=======

>>>>>>> bbaf92c40d830574fac79e46e6d28c3967367477
using namespace std;


class Kunde {

private:
<<<<<<< HEAD
    vector <int> vKunde;
     int kNr,           ///unike kundenummer og skal sorteres på
         tlf;       ///
    string navn,        ///kunde navn
            gate,       ///gateaddresse(gate + nr)
=======
     int kNr,           /// Unik kundenummer og skal sorteres på
         tlf;           ///
    string navn,        /// Kunde navn
            gate,       /// Gateaddresse(gate + nr)
>>>>>>> bbaf92c40d830574fac79e46e6d28c3967367477
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

    ~Kunde();               ///destructor
   ///andre funskjoner
    void skrivTilFil(ofstream& utfil);

    void lesFraFil();
    void lesData();
    void skrivData();
    int hentID();
   string hentNavn();
   void endreKunde();
   
   
   

};

#endif

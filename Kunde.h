/**
*
*@author: Abdisalan M. Husein, Mahamed Hassan Said, Elias Touil, NTNU Gjøvik
*@file: Kunde.h.
*
*/


#pragma once

#ifndef __KUNDE_H                  //  Ensures that this file will be
#define __KUNDE_H                  //    included only ONCE in each file.
#include "LesData3.h"
#include "enum.h"
#include "conster.h"
#include <fstream>
#include<vector>
#include "Sone.h"
#include "Soner.h"
#include <string>


using namespace std;

class Kunde {

private:
    vector <int> vKunde;    //sonenummr kunden er interseeert i
     int kNr,           ///unike kundenummer og skal sorteres på
         tlf;       ///
    string navn,        ///kunde navn
            gate,       ///gateaddresse(gate + nr)
            poststed,   /// (postnr + sted)
            mail;           /// mail til vedkommende
    Boligtype boligType;         /// 'Leilighet' eller 'Enebolig' -kundens interesse


public:
    Kunde();            ///default constructor
    Kunde(int nr);       ///copy constructor
    Kunde(ifstream &inn, int nr);
    //~Kunde();               ///destructor
   ///andre funskjoner
    void skrivTilFil(ofstream& utfil);
   // void lesFraFil();
    void lesData();
    void skrivData();
    int hentID();
   string hentNavn();
  // void endreKunde();
   void hentenKundoversikt(ofstream& ut);
   void soneEndre();
   void slettSone();


   

   
   
   

};
#endif

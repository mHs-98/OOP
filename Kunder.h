#pragma once
#ifndef __KUNDER_H                  //  Ensures that this file will be
#define __KUNDER_H                  //    included only ONCE in each file.

#include "LesData3.h"
#include <fstream>
#include <iostream>
#include <list>

using namespace std;
class Kunde;
class Kunder{
private:
    list<Kunde*> kundeListe;
    int sisteNr;
public:
    Kunder();           ///default connstructor
    Kunder(ifstream &inn);  ///leser inn egne data vha constructor
    void skrivMeny();
    void KundeHandling();
    void nyKunde();         /// legger ny kunde inni lista
   virtual void lesFraFil();
   virtual void skrivTilFil();
   void skrivHovedData();
   void enKunde(int& nr);
   bool skrevetUtPaa(const int pNr) const;
   void kundeSkrivAlt();
   void endreKunder(int& nr);
   void slettKunde(int& nr);


  // int finnes(const int nr)const;
  



};
#endif // __KUNDER_H

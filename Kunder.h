#ifndef __KUNDER_H                  //  Ensures that this file will be
#define __KUNDER_H                  //  included only ONCE in each file.

#include <iostream>
#include <fstream>
#include <list>
#include "Soner.h"
#include "Sone.h"
#include <cstring>
#include <string>
#include "Kunde.h"



class Kunder{
private:
    std::list<Kunde*> kundeListe;           //  list med pekere til 'Kunde'
    int sisteNr;
public:
  // int finnes(const int nr)const;
    Kunder();                               //default connstructor
    Kunder(std::ifstream &inn);             //leser inn egne data vha constructor
    void    skrivMeny();
    void    KundeHandling();
    void    nyKunde();                      // legger ny kunde inni lista
    virtual void lesFraFil(); 
    virtual void skrivTilFil(); 
    void    skrivHovedData();
    void    enKunde(int& nr);
    bool    skrevetUtPaa(const int pNr) const;
    void    kundeSkrivAlt();
    void    endreKunder(int& nr);
    void    slettKunde(int& nr);
    void  kundeOversikt();
    
    //int   finnes(const int nr)const;
 };


#endif // __KUNDER_H

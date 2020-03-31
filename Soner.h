#pragma once

#ifndef __SONER_H                  //  Ensures that this file will be
#define __SONER_H

#include <iostream>
#include <fstream>
#include <map>
#include "LesData3.h"


class Sone;
class Soner {
private:
    int sisteSNr;   /// Forløpende økende automatisk nummmerering av alle nye oppdrag/bolig
    std::map <int, Sone*> gSoner;    /// Alle aktuelle unikt nummererte Soner

public:
    Soner();
    ~Soner();
    Soner(int sisNr) {sisNr = sisteSNr;}
    void skrivAlleSoner();
    void nySone(const int sNr);
    void soneHandling();
    void skrivMeny();
    void hentEnSone();
};


#endif
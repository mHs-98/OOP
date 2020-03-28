#pragma once

#ifndef __SONER_H                  //  Ensures that this file will be
#define __SONER_H

#include <iostream>
#include <fstream>
#include <map>
#include "LesData3.h"

using namespace std;


class Sone;
class Soner {
private:
    int sisteSNr;   /// forløpende økende automatisk nummmerering av alle nye oppdrag/bolig
    map <int, Sone*> gSoner;    ///alle aktuelle unikt nummererte Soner

public:
    Soner();
    Soner(int sisNr);
    ~Soner();
    void nySone(const int sNr);
    void skrivMeny();
    void soneHandling();
    void skrivEnSone(const int sNr);
    void skrivAlleSoner();
    void endreSone(const int sNr);
    void slettSone(const int sNr);
};


#endif
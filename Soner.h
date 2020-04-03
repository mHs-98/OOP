#pragma once

#ifndef __SONER_H                  //  Ensures that this file will be
#define __SONER_H

#include <iostream>
#include <fstream>
#include <map>
#include "LesData3.h"
#include "Sone.h"
#include "Soner.h"
#include <string>


class Soner {
private:
    int sisteSNr;   /// Forlpende kende automatisk nummmerering av alle nye oppdrag/bolig
    std::map <int, Sone*> gSoner;    /// Alle aktuelle unikt nummererte Soner

public:
    Soner();
    //~Soner();
    void skrivAlleSoner();
    void nySone(const int sNr);
    void endreSone(const int sNr);
    void slettSone(const int sNr);
    void soneHandling();
    void soneMeny();
    bool finnes( int sNr) const;
    void nyOppdrag(int& snNr);
    void oppdragMeny();
    void skrivTilFil();
    void lesFraFil();
    void hentEnsone();
    void hentEnOPPdrag();
    void soneforKOversikt(int nr, std::ofstream& ut);
    //void kundOversikt(int nr);




};


#endif

/**
*Soner.h, deklerasjonsklassen
*@author: Abdisalan M. Husein, Mahamed Hassan Said, Elias Touil, NTNU Gjøvik
*@file: Soner.h.
*
*/


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
    void nySone( int sNr);
    void endreSone( int sNr);
    void slettSone( int sNr);
    void soneHandling(char valg);
    void soneMeny();
    bool finnes( int sNr) const;
    void nyOppdrag(int& snNr);
    void oppdragMeny();
    void skrivTilFil();
    void lesFraFil();
    void hentEnsone();
    void hentEnOPPdrag();
    void soneforKOversikt(int nr, std::ofstream& ut);
    void oppdragSlett(int nr);






};


#endif

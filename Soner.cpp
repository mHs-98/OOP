#include <iostream>
#include <fstream>
#include "LesData3.h"
#include "Soner.h"
#include "Sone.h"
#include "conster.h"
#include <map>

using namespace std;


class Sone;

/**
 * 
 */ 
Soner::Soner() {
    gSoner.insert(pair <int, Sone*>(sisteSNr++, new Sone));
    sisteSNr = 0;        /// Første kunde må ha nr 1
}

/**
 * 
 */ 
Soner::~Soner() {

}

/**
 * 
 */ 
void Soner::skrivMeny() {
   cout  << "\tS N - Ny Sone\n"
         << "\tS 1 - Skriv ALT om EN Sone\n"
         << "\tS A - Skriv ALT om alle Sonene\n"
         << "\tQ   - Avslutt Soner\n";
}

/**
 * 
 */ 
void Soner::soneHandling() {
    skrivMeny();
    char valg;
    valg = lesChar("\nValg");
    int iNr = 1;
    
    while (valg != 'Q') {
        switch(valg){
            case 'N': nySone(iNr);          break;
            //case '1': hentEnSone();         break;
            case 'A': skrivAlleSoner();     break;
            //case 'E': endreSone(iNr);       break;
            //case 'S': slettSone(iNr);       break;
            default: skrivMeny();
        }
        valg = lesChar("\nValg");
    }
}

/**
 * 
 */ 
void Soner::nySone(int sNr)
{
    Sone* nySone;
    sNr = lesInt("SoneNr: ", 1, maxSoner);
    cout << "\n\nSone Nr " << sNr << endl;
    auto it = gSoner.find(sNr);   // Iterator som leter etter sNr
    if (it == gSoner.end()) {    // Leter etter duplikater
        nySone = new Sone;
        nySone->lesBeskrivelse();        // Leser beskrivelse til ny sone
        gSoner[sNr] = nySone;   // Sender data til data strukturen
    }
    else
        cout << "Duplikater tillates ikke!";
}

/**
 * 
 */ 
void Soner::skrivAlleSoner() {
    if(!gSoner.empty()) { /// Sjekker om datastrukturen er tom
        cout << "\n\tSkriver alle Sonene...\n";
        for (const auto & val : gSoner) {
            cout << "\n\n\t" << val.first;
            (val.second)->Sone::skrivData();
            cout << endl; /// Alle skriver seg selv på skjermen.
        }
    }
    else
    {
        cout << "\n\tIngen data av Soner fantes!\n\n";
    }
}

bool Soner::finnes( int sNr) const      //hjelpefunsjon som sikrer at sonenummeret eksisterer!
{
   /* auto it1 = gSoner.find(sNr);     //  Prøver å finne vha. medlemsfunksjon.
    if (it1 != gSoner.end()) {      //  Funn i (<map>):
        return sNr;               //  Returnerer selve nummeret
    }  return false;
    */
    for (const auto& val : gSoner) {
        if ((val.second)->hentSoneNr() == sNr )
            return sNr;
    }return false;
}
/** 
 * 
 */ 
void Soner::hentEnSone() {
    Sone temp; int nr = 0;
    temp.skrivEnSone(nr); // Makes a temp from the other class and sends it to the function
}
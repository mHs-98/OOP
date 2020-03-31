#include <iostream>
#include <fstream>
#include "LesData3.h"
#include "Soner.h"
#include "Sone.h"
#include "conster.h"
#include <map>

//extern Sone gBoliger;
using namespace std;


class Sone;
Soner::Soner() {
    gSoner.insert(pair <int, Sone*>(sisteSNr++, new Sone));
    sisteSNr = 0;        /// Første Sone maa ha nr 1
}


void Soner::skrivMeny() {
    cout << "\tS N - Ny Sone\n"
        << "\tS 1 - Skriv ALT om EN Sone\n"
        << "\tS A - Skriv ALT om alle Sonene\n"
        << "\tS E - Endre en Sone\n"
        << "\tS S - Slett en Sone\n"
        << "\tQ   - Avslutt programmet\n";
}


void Soner::soneHandling() {
    skrivMeny();
    char valg;
    valg = lesChar("\nValg: ");
    int iNr = 1;

    while (valg != 'Q') {
        switch (valg) {
        case 'N': nySone(iNr);          break;
            //case '1': skrivEnSone(iNr);     break;
        case 'A': skrivAlleSoner();     break;
            //case 'E': endreSone(iNr);       break;
            //case 'S': slettSone(iNr);       break;
        default: skrivMeny();

        }
        valg = lesChar("\nValg: ");
    }
}

void Soner::nySone(int sNr)
{
    Sone* nySone;

    //for (const auto & val : gSoner) {
    sNr = lesInt("SoneNr: ", 1, maxSoner);
    cout << "\nSone Nr " << sNr << endl;
    //if (val.second->hentSoneNr() == sNr) {
    auto it = gSoner.find(sNr);   // Iterator som leter etter sNr
    if (it == gSoner.end()) {    // soneNummer ble ikke funnet
        nySone = new Sone;
        nySone->lesBeskrivelse();        // Leser data til ny sone
        gSoner[sNr] = nySone;   // Sender data til data strukturen
    }
    else                        // sonenummer eksisterer
        cout << "Duplikater tillates ikke!";
    //}
//}
}

void Soner::skrivAlleSoner() {
    if (!gSoner.empty()) { /// Sjekker om datastrukturen er tom
        cout << "\n\tSkriver alle Sonene...\n";
        for (const auto& val : gSoner) {
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
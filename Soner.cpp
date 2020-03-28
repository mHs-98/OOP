#include <iostream>
#include <fstream>
#include "LesData3.h"
#include "Soner.h"
#include "Sone.h"
#include "conster.h"
#include <map>

using namespace std;


class Sone;
Soner::Soner() {
    gSoner[1] = {0};
    sisteSNr = 0;        /// Første kunde må ha nr 1
}


void Soner::skrivMeny() {
   cout  << "\tS N - Ny Sone\n"
         << "\tS 1 - Skriv ALT om EN Sone\n"
         << "\tS A - Skriv ALT om alle Sonene\n"
         << "\tS E - Endre en Sone\n"
         << "\tS S -  Slett en Sone\n"
         << "\tQ   -  Avslutt programmet\n";
}


void Soner::soneHandling() {
    skrivMeny();
    char valg;
    valg = lesChar("\nValg: ");
    int iNr = 0;
    
    while (valg != 'Q') {
        switch(valg){
            case 'N': nySone(iNr);          break;
            case '1': skrivEnSone(iNr);     break;
            case 'A': skrivAlleSoner();   break;
            case 'E': endreSone(iNr);        break;
            case 'S': slettSone(iNr);        break;
            default: skrivMeny();

        } valg = lesChar("\nValg?: ");
    }
}


void Soner::nySone(const int sNr)
{
    Sone* nySone;

    for (const auto & val : gSoner) {
        if (val.second->hentSoneNr() == sNr) {
            auto it = gSoner.find(sNr);   // Iterator som leter etter sNr
            if (it == gSoner.end()) {    // Leter etter duplikater
                nySone = new Sone;
                nySone->lesBeskrivelse();        // Leser data til ny sone
                gSoner[sNr] = nySone;   // Sender data til data strukturen
                /// @todo: Nye boliger opprettes vha. Kommandoen "O N" 
            }
            else
                cout << "Duplikater tillates ikke!";
        }
    }
}


void Soner::skrivEnSone(const int sNr) {

}


void Soner::skrivAlleSoner() {
    if(!gSoner.empty()) { // Sjekker om datastrukturen er tom
        cout << "\n\tSkriver alle Sonene...\n";
        for (const auto & val : gSoner) {
            cout << "\n\n\t" << val.first;
            (val.second)->skrivData();  // Alle skriver seg selv på skjermen.
            cout << endl;
        }
    }
    else
    {
        cout << "\n\tIngen data av personer fantes!\n\n";
    }
}

void Soner::slettSone(const int sNr) {

}

void Soner::endreSone(const int sNr){

}


void Sone::lesBeskrivelse() {
    string soneBeskrivelse;
    cout << "\n\nSkriv en kort beskrivelse om sonen: ";
    getline(cin, soneBeskrivelse); //Leser inn sonens beskrivelse
}

void Sone::skrivTilFil() {

}
void Sone::lesFraFil() {

}

void Sone::skrivData() {

}
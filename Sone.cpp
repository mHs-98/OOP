#include <iostream>
#include <fstream>
#include "LesData3.h"
#include "Soner.h"
#include "Sone.h"
#include "conster.h"
#include "Bolig.h"
#include <map>

using namespace std;



void Sone::lesBeskrivelse() {
    cout << "\n\nSkriv en kort beskrivelse om sonen: ";
    getline(cin, soneBeskrivelse); //Leser inn sonens beskrivelse
}

void Sone::skrivTilFil() {

}
void Sone::lesFraFil() {

}

void Sone::skrivData() {
    cout << "\t";
    cout << "\n\tSone Nr: " << unikSNr
        << "\tBeskrivelse: " << soneBeskrivelse;

}

/// @todo: Lage Bolig::skrevetPaa() i Bolig.h
void Sone::skrivEnSone(int sNr) { // g gjennom boliger og skrive ut en bolig
    /*if (!gBoliger.empty()) {
        sNr = lesInt("Sone nr: ", 1, maxSoner);
        for (const auto val : gBoliger) {
            if (val.second->skrevetUtPaa(sNr)) {
                val.second->skrivEnOppdrag(sNr);
                if ( (sNr % 5) != 0) {
                cout << "\n\n\tTrykk Paa ENTER for  fortsette";
                cin.get();
            }
            }
        }

    }
    else
    {
        cout << "\n\tIngen data av Soner fantes!\n\n";
    }
    */
}

#include <iostream>
#include <fstream>
#include "LesData3.h"
#include "Soner.h"
#include "Sone.h"
#include "conster.h"
#include "Bolig.h"
#include <map>

using namespace std;

/**
 * Leser inn sonens beskrivelse
 */ 
void Sone::lesBeskrivelse() {
    cout << "\nSkriv en kort beskrivelse om sonen: ";
    getline(cin, soneBeskrivelse);
}

/**
 * 
 * 
 * 
 */ 
void Sone::skrivTilFil() {
    
}

/**
 * 
 * 
 * 
 */ 
void Sone::lesFraFil() {

}

/**
 * 
 * 
 * 
 */ 
void Sone::skrivData() {
    cout << "\t";
    cout << "\tBeskrivelse: " << soneBeskrivelse;
}

/**
 * G�r gjennom alle boliger og skriver ut en bolig
 * 
 * @see: Bolig.h, Bolig.cpp
 */ 
void Sone::skrivEnSone(int sNr) {
    /*
    if (!gBoliger.empty()) {
        int tmp = 0;   /// Variable for � telle hvor mange boliger ble utskrevet
        sNr = lesInt("Sone nr: ", 1, maxSoner); /// Vedkommende SoneNr
        for (const auto val : gBoliger) {   /// G�r gjennom boliger
            if (gBoliger[sNr]->skrevetUtPaa(sNr)) {  /// Om SoneNr er lik OppdragsNr
                gBoliger[sNr]->skrivData();         
                tmp++;
                if ((tmp % 5) == 0) {        /// Stans utskrift hver 5 Oppdrag
                cout << "\n\n\tTrykk P� ENTER for � fortsette"; 
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
/**
 *   @file      Bolig.cpp
 *   @author    Gruppe 12, NTNU
 */

#include <iostream>
#include <fstream>
#include "LesData3.h"
#include "Soner.h"
#include "Sone.h"
#include "conster.h"
#include "Bolig.h"
#include <map>
#include "Enebolig.h"
#include <string>

using namespace std;

/**
 * Leser inn klassens innhold fra filen
 * @param   in - Filobjektet egne data leses inn fra
 * @param   snr - Sone Nr
 */ 
Sone::Sone(int snr,  ifstream& in) {
    unikSNr = snr;
    getline(in, soneBeskrivelse);
    for (auto val : gBoliger) {
        val->lesFraFil();
    }
}

/**
 * Skriver ut klassens innhold til filen
 * 
 * @param   in - Filobjektet egne data leses inn fra
 */ 
void Sone::skrivTilFil(ofstream & ut) const {
    ut << unikSNr << "\t" << soneBeskrivelse << endl;
    for (auto val : gBoliger) {
        val->skrivTilFil(ut);
    }
}

/**
 * Leser Sonens beskrivelse
 */ 
void Sone::lesBeskrivelse() {
    cout << "\n\nSkriv en kort beskrivelse om sonen: ";
    getline(cin, soneBeskrivelse); //Leser inn sonens beskrivelse

}

/**
 * Intialerer Eksempel Sone
 * 
 * @param   nr - Sone Nr
 */ 
Sone::Sone(int nr) {
    unikSNr = nr;
    soneBeskrivelse = "Eksempel Beskrivelse";
};

/**
 * Skriver Sone sin data
 */ 
void Sone::skrivData() {
    cout << "\t";
    cout << "\n\tSone Nr: " << unikSNr
        << "\tBeskrivelse: " << soneBeskrivelse;

}

/**
 *  Går gjennom boliger i en Sone og skriver alt om dem
 * 
 * @see     Soner::hentEnSone()
 */
void Sone::skrivEnSone() {
    cout << "\nSone Nr: " << unikSNr;
   if (!gBoliger.empty()) {
        for (int i = 0; i < gBoliger.size(); i++) { // Går gjennom boligen
            gBoliger[i]->skrivData();   // Skriver bolig sin data
            cout << "\n\n";
            if ( ((i+1) % 5) == 0) {   // Stans utskrift hver 5 boliger
                cout << "\n\n\tTrykk Paa ENTER for aa fortsette";
                cin.get();
            }
        }

    }
    else
    {
        cout << "\n\tFant Ingen data om Boliger i denne Sonen!\n\n";
    }
    
}

/**
 * Lager ny oppdrag og legger den inn i datastrukturen
 * 
 * @param   nr - Sone Nr
 * @see     Bolig::lesData()
 */ 
void Sone::lagnyOppdrag(int nr)
{
    Bolig* nyBolig = nullptr;
   // nyBolig->nyOppdrag();       // Kaller paa funskjone i bolig klassen
                                  // Veldig knotete aa gjøre det paa men, maa man saa man!

    char boligType;

    do {                                     //  Leser ALLTID 'A' eller 'S':
        boligType = lesChar("\tL(eilighet) eller E(nebolig)");
    } while (boligType != 'L' && boligType != 'E');

    switch (boligType) {                    //  Lager en ny aktuell kjører:
    case 'L':  nyBolig = new Bolig(nr);     break;
    case 'E':  nyBolig = new Enebolig(nr);  break;
    }

    nyBolig->lesData();
    gBoliger.push_back(nyBolig);// Ny oppdraget legges bakerst i vektoren
}

/**
 * Går gjennom alle oppdrag og skriver sin data
 * 
 * @param   nr - Sone Nr
 */ 
void Sone::enOppdrag(int nr)
{
    for (auto val : gBoliger) { // Går gjennom alle oppdrag
        if(nr ==val->hentID())        // Riktig opdragsdnummer?
            val->skrivData();   // Skriv sin egen data?
    }

}

/**
 * Skriver Sonens boliger innhold
 * 
 * @param   ut - ofstream referanse variable
 * @see     Bolig::skrivTilFil()
 */ 
void Sone::enkundeoversikt(ofstream& ut)
{
    
    for (auto val : gBoliger) {
        val->skrivTilFil(ut);
    }

}

/*void Sone::nyOppdrag(int& snNr)
{
    Bolig*      nyBolig      = nullptr;              //  Peker til nye aktuell ene/bolig.
    
    do {
        snNr = lesInt("Hvilken sone skal oppdraget opprettes i: ", 1, maxSoner);
        if (gsonene.finnes(snNr)) {
            nyBolig->nyOppdrag();       //kaller på nyOppdrag fra Bolig
            gBoliger.push_back(nyBolig); 
        }
        else cout << "Sonenummern finnnes ikke"
            << "tast en sonemmuner mellom 1 og ";
    } while (!gsonene.finnes(snNr));
}*/

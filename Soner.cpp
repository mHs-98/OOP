/**
 *   @file     Soner.cpp
 *   @author   Gruppe 12, NTNU
 */

#include <iostream>
#include <fstream>
#include "LesData3.h"
#include "Soner.h"
#include "Sone.h"
#include "conster.h"
#include <map>
#include <string>

using namespace std;


Soner::Soner() {
    sisteSNr = 0;        // Første Sone maa ha nr 1
}

/**
 *  Skriver programmets menyvalg/muligheter på skjermen.
 */
void Soner::soneMeny() {
    cout << "\tS N - Ny Sone\n"
        << "\tS 1 - Skriv ALT om EN Sone\n"
        << "\tS A - Skriv ALT om alle Sonene\n"
        << "\tQ   - Avslutt programmet\n";
}

/**
 * Handler Sonens menyvalg/muligheter
 */ 
void Soner::soneHandling() {

    //  if etterfølgt av en switch! 
    char valg;
    int iNr = 0;
    cout << "Du befinner deg paa ingen-manns-land\n"
        << "Tast 'S'one eller 'O'ppdrag";
    valg = lesChar("\nValg: ");
    while (valg != 'Q') 
  
    {
      
        switch (valg) {
        case 'S':
            soneMeny();
            valg = lesChar("\nValg: ");
            switch (valg)
            {
            case 'N': nySone(iNr);
                break;
            case 'A': skrivAlleSoner();     break;
            case '1': hentEnSone();          break;

            default: soneMeny();

                break;
            }break;

        case 'O':
            oppdragMeny();
            valg = lesChar("\nValg: ");
            switch (valg)
            {
            case 'N': nyOppdrag(iNr);          break;
            case '1': hentEnOPPdrag();

            default: oppdragMeny();

                break;
            }
            break;

        } valg = lesChar("les paa nytt elle Q");
    }
    }

/**
 *  Lager en ny sone og sender den inn i vectoren
 * @param   sNr - Sone sin Nr
 * @see     Sone::lesBeskrivelse()
 */ 
void Soner::nySone(int sNr)
{
    Sone* nySone;

    sNr = lesInt("SoneNr: ", 1, maxSoner);
    cout << "\nSone Nr " << sNr << endl;
    auto it = gSoner.find(sNr);   // Iterator som leter etter sNr
    if (it == gSoner.end()) {    // soneNummer ble ikke funnet
        nySone = new Sone(sNr);
        nySone->lesBeskrivelse();        // Leser data til ny sone
        gSoner[sNr] = nySone;   // Sender data til data strukturen
    }
    else                        // sonenummer eksisterer
        cout << "Duplikater tillates ikke!";
    }


/**
 * Skriv Soners innhold til 'SONER.DTA'
 * 
 * @see      Sone::skrivData()
 * @file     'SONER.DTA'
 */ 
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

/**
 * Skriv Soners innhold til 'SONER.DTA'
 * 
 * @see     Sone::skrivTilFil()
 * @file    'SONER.DTA'
 */ 
void Soner::skrivTilFil() {
    ofstream utFil("SONER.DTA");
    cout << "\n\tSkriver ut til filen 'SONER.DTA'...\n\n";
    if (utFil) {
        for (const auto & val : gSoner) {
            (val.second)->skrivTilFil(utFil); // Alle skriver seg selv til fil.
        }
        utFil.close();
    }
    else
        cout << "\n\tFinner ikke filen 'SONER.DTA'! \n\n";
}

/**
 * Leser fra 'SONER.DTA' Filen
 * 
 * @file     'SONER.DTA'
 */ 
void Soner::lesFraFil() {
    ifstream innFil("SONER.DTA"); 
    int sNr;
    cout << "\n\tLeser fra filen 'SONER.DTA'...\n\n";
    if (innFil) {
        innFil >> sNr;
        innFil.ignore();
        while (!innFil.eof()) {
            gSoner.insert(pair <int, Sone*>(sNr, new Sone(sNr, innFil)));
        }
        innFil.close();
    }
    else
        cout << "\n\tFinner ikke filen 'SONER.DTA'!\n\n";
    
}

/**
 *  Skriver alt om en sone
 * 
 * @see     Sone::skrivEnSone()
 */
void Soner::hentEnSone()
{
        int snNr = lesInt("Hvilken sone skal du se <nr>: ", 1, maxSoner);
        auto it = gSoner.find(snNr);   // Iterator som leter etter sNr
        if (it != gSoner.end()) {    // soneNummer ble  funnet
            it->second->skrivEnSone();
        }
        else                        // sonenummer eksisterer
            cout << "finnese ikke!";
}

/**
 *  Henter Sone sin data i spesifikk oppdrag 
 * 
 * @see     Sone::enOppdrag()
 */
void Soner::hentEnOPPdrag()
{
    int  oppdragsnummer = lesInt("Hvilken oppdragsnummer : ", 1, sisteSNr);
    for (auto val : gSoner) {
          val.second->enOppdrag(oppdragsnummer); //Skriver en oppdrag
        }
    
}

/**
 * Henter Sone Nr og vedkommende Sone sin data
 * 
 * @param   ut - Ofstream variable
 * @param   nr - Sone sin Nr
 * @see     Sone::enkundeoversikt()
 */ 
void Soner::soneforKOversikt(int nr, ofstream& ut)
{
    gSoner[nr]->enkundeoversikt(ut); 
    cout << "";
}


/**
 * Bool funksjon som return om sonen finnes eller ikke
 * 
 * @see     Sone::hentSoneNr()
 * @file    'Sone.h'
 */
bool Soner::finnes( int sNr) const      //hjelpefunsjon som sikrer at sonenummeret eksisterer!
{
  
    for (const auto& val : gSoner) {
        if ((val.second)->hentSoneNr() == sNr ) /// Fant Sone Nr?
            return true;
    }return false;
    
}

/**
 * Lager ny oppdrag som legges in i vectoren
 * 
 * @param   snNr -  Sone sin Nr
 * @file    'Soner.h'
 */
void Soner::nyOppdrag(int& snNr)
{
        snNr = lesInt("Hvilken sone skal oppdraget opprettes i: ", 1, maxSoner);
        auto it = gSoner.find(snNr);   // Iterator som leter etter sNr
        if (it != gSoner.end()) {    // SoneNummer ble  funnet
            it->second->lagnyOppdrag(++sisteSNr);
        }
        else                        // Sonenummer eksisterer
            cout << "Duplikater tillates ikke!";
}

/**
 * Skriver oppdrag menyvalg/muligheter på skjermen.
 */
void Soner::oppdragMeny()
{
    cout << "Velkommen til Oppdrag-verden!\n"
        << "Her er mulighetenen du har:\n\t"
        << " N: Oprett ny oppdrag\n"
        << "\t1<nr>: Skriv alt om EN gitt oppdrag\n"
        << "\tS<nr>: Slett EN gitt oppdrag\n";
}
    



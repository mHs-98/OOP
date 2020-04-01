#include <iostream>
#include <fstream>
#include "LesData3.h"
#include "Soner.h"
#include "Sone.h"
#include "conster.h"
#include <map>

using namespace std;
//Sone gsone;
Soner::Soner() {
    sisteSNr = 0;        // Første Sone maa ha nr 1
}


void Soner::soneMeny() {
    cout << "\tS N - Ny Sone\n"
        << "\tS 1 - Skriv ALT om EN Sone\n"
        << "\tS A - Skriv ALT om alle Sonene\n"
        << "\tQ   - Avslutt programmet\n";
}


void Soner::soneHandling() {

    //if etterfølgt av en switch! 
    char ch;
    cout << "Du befinner du deg paa ingen-manns-land\n"
        << "Tast 'S'one eller 'O'ppdrag";
    cin >> ch;
    if (ch = 'S')
    {
        soneMeny();
        char valg;
        valg = lesChar("\nValg: ");
        int iNr = 0;
        //Sone tmpSone;
        while (valg != 'Q') {
            switch (valg) {
            case 'N': nySone(iNr);          break;
                //case '1': skrivEnSone(iNr);     break;
            case 'A': skrivAlleSoner();     break;
                //case 'E': endreSone(iNr);       break;
                //case 'S': slettSone(iNr);       break;
            default: soneMeny();

            }
        }
    }
    else if (ch = 'O')
    {
        oppdragMeny();
        char valg;
        valg = lesChar("\nValg: ");
        int iNr = 0;

        while (valg != 'Q') {
            switch (valg) {
            case 'N': nyOppdrag(iNr);          break;
                //  case 'S': slettOppdrag();     break;
            default: oppdragMeny();

            }valg = lesChar("Gjøre paa nytt eller tast Q\n");
        }
    }
    else
    {
        cout << "Det var ikke riktig valg prøv paa nytt!";



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
        nySone = new Sone(sNr);
        nySone->lesBeskrivelse();        // Leser data til ny sone
        gSoner[sNr] = nySone;   // Sender data til data strukturen
    }
    else                        // sonenummer eksisterer
        cout << "Duplikater tillates ikke!";
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
            return true;
    }return false;
    
}

void Soner::nyOppdrag(int& snNr)
{
        snNr = lesInt("Hvilken sone skal oppdraget opprettes i: ", 1, maxSoner);
        auto it = gSoner.find(snNr);   // Iterator som leter etter sNr
        if (it != gSoner.end()) {    // soneNummer ble  funnet
            it->second->lagnyOppdrag(++sisteSNr);
        }
        else                        // sonenummer eksisterer
            cout << "Duplikater tillates ikke!";
}

void Soner::oppdragMeny()
{
    cout << "Velkommen til Oppdrag-verden!\n"
        << "Her er mulighetenen du har:\n\t"
        << " N: Oprett ny oppdrag\n"
        << "1<nr>: Skriv alt om EN gitt oppdrag\n"
        << "S<nr>: Slett EN gitt oppdrag\n";
}
    



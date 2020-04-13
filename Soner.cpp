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

//skrivtilfil struktur ikke helt riktig!!

using namespace std;

Soner::Soner() {
    sisteSNr = 0;        // Første Sone maa ha nr 1
   // gSoner.insert(pair <int, Sone*>(sisteSNr, new Sone));
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
void Soner::soneHandling(char valg) {

    //if etterfølgt av en switch! 
   // char valg;
    int iNr = 0;
    cout << "Du befinner du deg paa ingen-manns-land\n"
        << "Tast 'S'one eller 'O'ppdrag";
   // valg = lesChar("\nValg: ");
    while (valg != 'Q') 
  
    {
      
        switch (valg) {
        case 'S':
            soneMeny();
            valg = lesChar("\nValg: ");
            switch (valg)
            {
            case 'N': nySone(iNr);           break;
            case 'A': skrivAlleSoner();     break;
            case '1':hentEnsone();          break;

            default: soneMeny();

                break;
            }break;

        case 'O':
            oppdragMeny();
            valg = lesChar("\nValg: ");
            switch (valg)
            {

            case 'N': nyOppdrag(iNr);          break;
            case 'S':  oppdragSlett(iNr);     break;
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


/**
 * Skriv Soners innhold til 'SONER.DTA'
 *
 * @see      Sone::skrivData()
 * @file     'SONER.DTA'
 */
void Soner::skrivAlleSoner() {
    if (!gSoner.empty()) {                  // Sjekker om datastrukturen er tom
        cout << "\n\tSkriver alle Sonene...\n";
        for (const auto& val : gSoner) {
            val.second->skrivData();
        }
       
    }
    else
    {
        cout << "\n\tIngen data av Soner fantes!\n\n";
    }
}

/***
 * Skriv Soners innhold til 'SONER.DTA'
 * 
 * @see     Sone::skrivTilFil()
 * @file    'SONER.DTA'
 */ 
void Soner::skrivTilFil() {
    ofstream utFil("SONER.DTA");
    cout << "\n\tSkriver ut til filen 'SONER.DTA'...\n\n";
    if (utFil) {
        utFil << sisteSNr << '\n';
        for (const auto & val : gSoner) {
            //utFil << val.first;
            (val.second)->skrivTilFil(utFil); // Alle skriver seg selv til fil.
        }
       /* for (int i = 1; i < gSoner.size(); i++) {
            gSoner[i]->skrivTilFil(utFil);
        }*/

       // utFil.close();
    }
    else
        cout << "\n\tFinner ikke filen 'SONER.DTA'! \n\n";
}

/**
 * Leser fra 'SONER.DTA' Filen
 * 
 * @file     'SONER.DTA'
 *@see          Sone::Sone(...)
 */ 
void Soner::lesFraFil() {
    ifstream innFil("SONER.DTA"); 
    int sNr;
   // int ant;
    cout << "\n\tLeser fra filen 'SONER.DTA'...\n\n";
    if (innFil) {
        innFil >> sisteSNr;
        innFil.ignore();
      //  cout << "\nforan while i soner::lesfrafil()\n";
        while (!innFil.eof()) {
            innFil >> sNr;
            gSoner.insert(pair <int, Sone*>(sNr, new Sone(sNr, innFil)));
          
        }
        innFil.close();
    }
    else
        cout << "\n\tFinner ikke filen 'SONER.DTA'!\n\n";
    
}
/**
 *  Skriver alt om EN gitt sone
 *
 * @see     Sone::skrivEnSone()
 */
void Soner::hentEnsone()
{

    int tmp  = 0;
    int snNr = lesInt("Hvilken sone skal du se <nr>: ", 1, maxSoner);
    auto it = gSoner.find(snNr);            // Iterator som leter etter sNr
    if (it != gSoner.end()) {               // soneNummer ble  funnet
        it->second->skrivEnSone(snNr);
        tmp++;
        if ((tmp % 5) == 0) {              //stans utskriften for hver 5.utskrift!
            cout << "\n\n\tTrykk Paa ENTER for  fortsette";
            cin.get();
        }
    }  else
    {
        cout << "\n\tIngen data av Soner fantes!\n\n";
    }

}
 
/**
 *  Henter Sone sin data i spesifikk oppdrag
 *
 * @see     Sone::enOppdrag()
 */
void Soner::hentEnOPPdrag()//henter
{
    int  oppdragsnummer = lesInt("Hvilken oppdragsnummer : ", 1, sisteSNr);
    for (auto val : gSoner) {
          val.second->enOppdrag(oppdragsnummer);
        }
    
}

/**
 * Henter Sone Nr og vedkommende Sone sin data, skal brukes i Kundeoversikt i kunder!
 *
 * @param   ut - Ofstream variable
 * @param   nr - Sone sin Nr
 * @see     Sone::enkundeoversikt()
 */
void Soner::soneforKOversikt(int nr, ofstream& ut)
{
    gSoner[nr]->enkundeoversikt(ut);
}

/**
*Sletter spesifikk oppdrag fra datastrukturen
*@see       Sone::slettEnOppdrag(...)
* @param   nr - Sone Nr
* */

void Soner::oppdragSlett(int nr)
{
    nr = lesInt("\tSlette/fjerne ALLE oppdrag(er) med nummer:  ", 1, sisteSNr);

    for (auto val : gSoner) {
        val.second->slettEnOppdrag(nr);
    }
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
        if ((val.second)->hentSoneNr() == sNr )
            return true;
    }return false;
    
}

/**
*Lager ny oppdrag som legges in i vectoren
*
* @param   snNr - Sone sin Nr
*@see       Sone::lagnyOppdrag(...)
* @file    'Soner.h'
* */
void Soner::nyOppdrag(int& snNr)
{
    string temp;
        snNr = lesInt("Hvilken sone skal oppdraget opprettes i: ", 1, maxSoner);
        auto it = gSoner.find(snNr);   // Iterator som leter etter sNr
        if (it != gSoner.end()) {    // soneNummer ble  funnet
            it->second->lagnyOppdrag(++sisteSNr);
        }
        else                        // sonenummer eksisterer
            cout << "Duplikater tillates ikke!";
        getline(cin, temp);
}
/**
 * Skriver oppdrag menyvalg/muligheter på skjermen.
 */
void Soner::oppdragMeny()
{
    cout << "Velkommen til Oppdrag-verden!\n"
        << "Her er mulighetenen du har:\n\t"
        << "N: Oprett ny oppdrag\n"
        << "\t1<nr>: Skriv alt om EN gitt oppdrag\n"
        << "\tS<nr>: Slett EN gitt oppdrag\n";
}
    



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
   // gSoner.insert(pair <int, Sone*>(sisteSNr, new Sone));
}


void Soner::soneMeny() {
    cout << "\tS N - Ny Sone\n"
        << "\tS 1 - Skriv ALT om EN Sone\n"
        << "\tS A - Skriv ALT om alle Sonene\n"
        << "\tQ   - Avslutt programmet\n";
}


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
            case 'N': nySone(iNr);
                break;
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
           //  case 'S': slettOppdrag();     break;
            case '1': hentEnOPPdrag();

            default: oppdragMeny();

                break;
            }
            break;

        } valg = lesChar("les paa nytt elle Q");
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
            cout << "\n\n\t inni soner::skrivalle()\n" << val.first;
            val.second->skrivData();
        }
       /* for (int i = 1; i<=gSoner.size();i++){
            gSoner[i]->skrivData();
            cout << endl; /// Alle skriver seg selv på skjermen.
        }*/
    }
    else
    {
        cout << "\n\tIngen data av Soner fantes!\n\n";
    }
}

/**
 * 
 * 
 * 
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
 * 
 * 
 * 
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
           // innFil >> sisteSNr;
            //skrivAlleSoner();
            //cout << "\netter inser\n";
        }
        innFil.close();
    }
    else
        cout << "\n\tFinner ikke filen 'SONER.DTA'!\n\n";
    
}

void Soner::hentEnsone()
{
    int snNr = lesInt("Hvilken sone skal du se <nr>: ", 1, maxSoner);
    auto it = gSoner.find(snNr);   // Iterator som leter etter sNr
    if (it != gSoner.end()) {    // soneNummer ble  funnet
        it->second->skrivEnSone(snNr);
    }
}
    /* if (!gBoliger.empty()) {
        sNr = lesInt("Sone nr: ", 1, maxSoner);
        for (const auto val : gBoliger) {
            if (val->hentID->skrevetUtPaa(sNr)) {
                val->hentID->skrivEnOppdrag(sNr);
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

}
  
        int snNr = lesInt("Hvilken sone skal du se <nr>: ", 1, maxSoner);
        auto it = gSoner.find(snNr);   // Iterator som leter etter sNr
        if (it != gSoner.end()) {    // soneNummer ble  funnet
            it->second->skrivEnSone(snNr);
        }
        else                        // sonenummer eksisterer
            cout << "finnese ikke!";
}*/

void Soner::hentEnOPPdrag()//henter
{
    int  oppdragsnummer = lesInt("Hvilken oppdragsnummer : ", 1, sisteSNr);
    for (auto val : gSoner) {
          val.second->enOppdrag(oppdragsnummer);
        }
    
}

void Soner::soneforKOversikt(int nr, ofstream& ut)
{
    gSoner[nr]->enkundeoversikt(ut);
}

void Soner::hjelpKAiSOner()
{
    int nr;
    gSoner[nr]->hjelpeKA();

}




bool Soner::finnes( int sNr) const      //hjelpefunsjon som sikrer at sonenummeret eksisterer!
{
  
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
        << "N: Oprett ny oppdrag\n"
        << "\t1<nr>: Skriv alt om EN gitt oppdrag\n"
        << "\tS<nr>: Slett EN gitt oppdrag\n";
}
    



#include <iostream>
#include <fstream>
#include "LesData3.h"
#include "Kunder.h"
#include "Kunde.h"
#include <list>

using namespace std;

class Kunde;
Kunder::Kunder() {
    kundeListe = {0};
    sisteNr = 0;        /// Første kunde må ha nr 1
}

void Kunder::skrivMeny(){

   cout  << "\tK N - NY Kunde\n"
         << "\tK 1 - SKRIV ALT om EN kunde\n"
         << "\tK A - Skriv ut om alt av alle kundene\n"
         << "\tK E - Endre Kundenes data (soner)\n"
         << "\tK S -  Slett en Kunde \n"
         << "\tK O  - Kunde Oversikt til \n"
         << "\tQ - Quit / avslutt\n";
}

 void Kunder::KundeHandling() {
    skrivMeny();
    char valg;
    valg = lesChar("\nTa en Valg: ");
    while(valg != 'Q'){
        switch(valg){
            case 'N': nyKunde();        break;
          //  case '1': enKunde();        break;
         //   case 'A': kundeSkrivAlt();   break;
        //    case 'E': endreKunde();      break;
        //    case 'S': slettKunde();      break;
        //    case 'O': kundeOversikt();  break;
            default: skrivMeny();

        } valg = lesChar("\nGjore en gang til?: ");
    }
 }
void Kunder::nyKunde() {
   // int nr;
    Kunde* kunden = new Kunde();        ///kunde
    kunden->lesData();
    kundeListe.push_back(kunden);
    sisteNr++;
    
}

void Kunder::lesFraFil() {
    ifstream innfil("KUNDER.DTA");
    innfil >> sisteNr; innfil.ignore();
    Kunde* kunden;      ///hjepe-variabel
    int kundeNr;

    if(innfil){ ///filen eksister
              ///leser inn første kunden
    innfil>> kundeNr; innfil.ignore();
    while(!innfil.eof()){   ///mer å lese
            kunden = new Kunde(innfil, kundeNr);
            kundeListe.push_back(kunden); ///legg kunden inni lista


    }

    }

}

 void Kunder::skrivTilFil() {
    ofstream ut("KUNDER.DTA");
    ut << sisteNr;
    ut << kundeListe.size() << '\n';
    for (const auto& val : kundeListe)
    {
        val->skrivTilFil();
    }
}



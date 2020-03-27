#include<iostream>
#include<fstream>
#include "LesData3.h"
#include "Kunder.h"
#include "Kunde.h"
#include <list>
#include <iomanip>

using namespace std;

//class Kunde;
Kunder::Kunder() {
 kundeListe = {0};
    sisteNr = 0;        ///første kunde må ha nr 1
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
    int nr = 0;
    valg = lesChar("\nTa en Valg");
    while(valg != 'Q'){
        switch(valg){
            case 'N': nyKunde();        break;
            case '1': enKunde(nr);        break;
            case 'A': kundeSkrivAlt();   break;   
        //    case 'E': endreKunde();      break;
        //    case 'S': slettKunde();      break;
        //    case 'O': kundeOversikt();  break;
            default: skrivMeny();

        } valg = lesChar("\nvalg paa nytt eller 'Q'uit?");
    }
 }
void Kunder::nyKunde() {
   // int nr;
    Kunde* kunden = new Kunde();        ///kunde
    kunden->lesData();
    kundeListe.push_back(kunden);
    sisteNr++;  
    // punshSone()
    /*#
    # lager nykunde() inni main
    #kjører kunder::nykund()
    #fram main henter sonenummre fra bruker
    #fra main sjekkker at soneNR er valid-->vha Soner klase
    #hvis valid: legg til sonNR inni kundedatabase vha funskjon i kunder klasse
    alt:
        #nykunde() tar inn parameter
        nykunde(SOner& snr, )
    */

    
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
        val->skrivTilFil(ut);
    }
}

 void Kunder::skrivHovedData()
 {
     cout << " \nSå mange kunder finnes\n\t" << kundeListe.size();
     cout << "SistNr:\t\n" << sisteNr;
 }


 void Kunder::enKunde(const int nr)
 {
     
     skrivHovedData();
     for (const auto& val : kundeListe)     ///hent ut en kun
     {
         if (skrevetUtPaa(nr)) {   //  Utskrevet på aktuell pasient:
              val->skrivData();

         }

     }
 }

 bool Kunder::skrevetUtPaa(const int pNr) const
 {
     for (const auto& val : kundeListe) {
         if (val->hentID() == pNr)
             return pNr;
     }return false;

 }

 void Kunder::kundeSkrivAlt()
 {
     cout << "\n\tAlle " << kundeListe.size() << " hittil registrerte kundenavn:\n";
     for (const auto& val : kundeListe) {
         cout << "\t\t" << setw(2) << val + 1 << ":  " << val->hentNavn() << '\n';
      //   if (((val + 1) % 10) == 0) {              //  Stanser for hvert 10.navn:
             cout << "\t\t\t\t\t\tSkriv ENTER/CR .....\n";  cin.ignore();
         }
     }
 
 



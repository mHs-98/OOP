#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include "LesData3.h"
#include "Kunder.h"
#include "Kunde.h"
#include "Sone.h"
#include "Soner.h"
#include <list>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

extern Soner gSonene;

//class Kunde;
Kunder::Kunder() {
 kundeListe = list<Kunde*>();
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
            case 'E': endreKunder(nr);      break;
            case 'S': slettKunde(nr);      break;
           case 'O': kundeOversikt();  break;
            default: skrivMeny();

        } valg = lesChar("\nvalg paa nytt eller 'Q'uit?");
    }
 }
void Kunder::nyKunde() {
   // int nr;
    Kunde* kunden = new Kunde(++sisteNr);                   //kunde
   
    kunden->lesData();
    kundeListe.push_back(kunden);                       //nyeste kunden legges bakerst i lista 
    kundeListe.sort([]( Kunde* k1, Kunde* k2)           //sorterer etter kundenummer!
        {  return (k1->hentID() < k2->hentID());  });
}

void Kunder::lesFraFil() {      //leser kundens data fra fil
    cout << "\n\tLeser fra KUNDER.DTA\n";
    ifstream innfil("KUNDER.DTA"); 
    Kunde* kunden;      ///hjepe-variabler
    int kundeNr;
    //cout << "finer ikke kundenummer";
    if(innfil){ ///filen eksister
              ///leser inn første kunden
        innfil >> sisteNr;
        innfil >> kundeNr;
    while(!innfil.eof()){   ///mer å lese

            kunden = new Kunde(innfil, kundeNr);
            kundeListe.push_back(kunden); ///legg kunden inni lista
            innfil >> kundeNr;          //leser neste kunde
    }

    }

}

 void Kunder::skrivTilFil() {
    ofstream ut("KUNDER.DTA");
    ut << sisteNr << '\n';
    for (const auto& val : kundeListe)
    {
        val->skrivTilFil(ut);
    }
    cout << "\nSkriver til KUNDER.DTA\n";
}

 void Kunder::skrivHovedData()
 {
     cout << " \nSå mange kunder finnes\n\t" << sisteNr << '\n';
 }


 void Kunder::enKunde(int& nr)
 {
     
     skrivHovedData();
     cout << '\n';
     for (const auto& val : kundeListe)     ///hent ut en kun
     {
         cout << "Hvilken kundenummer vil du se?:\n\t";
         cin >> nr;

         if (skrevetUtPaa(nr)) {   //  Kunde finnes i lista:
             val->skrivData();

         }
         else {
             cout << "Det nummeret eksisterer ikke! "
                 << "tast et nummer mellom" << sisteNr << " og 1";
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
     int i = 0;
     for (const auto& val : kundeListe) {       ///for hver kund i lista
         val->skrivData();                      /// be skrive sin egen data ut på skjerm
         if (++i % 10 == 0){            ///stanst for hver 10.kunde
                 cout << "\t\t\t\t\t\tSkriv ENTER/CR .....\n";  cin.ignore();
             }
         }
     }

 

 void Kunder::endreKunder(int& nr)
 {
     nr = lesInt("Hvilken kunde skal endres", 1, sisteNr);
    
     {
         for (auto val : kundeListe) {
             if (val->hentID() == nr) {

                 cout << " \n\tHer ser du naavaerende data om kunden:\n";
                 val->skrivData();  //
             }
             else
             {
                 cout << "Ugyldig kundenummer!";
             }
             char valg;
             cout << "\t\nDu har to valg\n:"
                 << "'L'egge til nytt sone eller 'S'lette en sone fra vedkommende!\n";
             valg = lesChar("\nL eller S?: \n");
             while (valg != 'Q')
             {
                 switch (valg)
                 {
                 case 'L': val->soneEndre();    break;
                 case'S': val->slettSone();     break; 
                 default: cout << "Ugyldig valg";
                     break;
                 }
                 valg = lesChar("\nValg paa nytt eller 'Q'uit\n");
             } 



         }


     }
 }
 
 void Kunder::slettKunde(int& nr)
 {
         //int nr;                           //  Navn til gjenstand(er) å slette.
         int  antall = 0;                      //  Antall gjenstander med navnet.

         nr = lesInt("\tSlette/fjerne ALLE Kunde(er) med nummer:  ", 1, sisteNr);

         //  FINNER ANTALLET MED NAVNET:
         antall = count_if(kundeListe.begin(), kundeListe.end(),
             [nr](const auto& val) { return (val->hentID() == nr); });

         if (antall > 0) {                        //  Gjenstand(er) ble funnet:
             cout << "\n\tØnsker du VIRKELIG å slette/fjerne "
                 << ((antall > 1) ? "ALLE disse" : "denne");
             if (lesChar(" (j/N)") == 'J') {      //  VIL slette alle:
                                                  //  AKTUELLE SLETTES:
                 kundeListe.remove_if([nr](const auto& val)
                     { return (val->hentID() == nr); });
                 cout << "\n\t" << antall << " kunde er slettet!"
                     << "\n\tDet er nå " << kundeListe.size()
                     << " kunder tilbake i listen.\n";
             }
             else
                 cout << "\n\tOK - ingen gjenstand har blitt slettet.\n";
         }
     }
     

 void Kunder::kundeOversikt()
 {
     int nr;
     cout << "\nSaa mange kunder finnes:" << kundeListe.size();
      nr = lesInt("Hvilken kunde vil du se:\n", 1,kundeListe.size());
    
   
  
    string filNavn = string("K") + to_string(nr) + string(".DTA");

    ofstream ut(filNavn);

    for (auto val : kundeListe) {
        if (val->hentID() == nr) {
            val->hentenKundoversikt(ut);
        }
    }  cout << "\n****Se paa K+nr.dta!****\n";
 }

 

 

 
 



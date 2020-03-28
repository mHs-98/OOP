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
        //    case 'O': kundeOversikt();  break;
            default: skrivMeny();

        } valg = lesChar("\nvalg paa nytt eller 'Q'uit?");
    }
 }
void Kunder::nyKunde() {
   // int nr;
    Kunde* kunden = new Kunde(++sisteNr);        ///kunde
    kunden->lesData();
    kundeListe.push_back(kunden);
    
    
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
    ut << sisteNr << '\n';
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
                 << "tast et nummer mellom" << kundeListe.max_size() << " og 1";
         }cin >> nr;
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
     for (const auto& val : kundeListe)     ///hent ut en kun
     {
         cout << "Hvilken kundenummer vil du endre?:\n\t";
         cin >> nr;

         if (skrevetUtPaa(nr)) {   //  kunden finnes
             cout << " \n\tHer ser du naavaerende data om kunden:\n";

             val->skrivData();
             

         }
         else {
             cout << "Det nummeret eksisterer ikke! "
                 << "tast et nummer mellom" << kundeListe.max_size() << " og 1";
         }
     }
 }
 void Kunder::slettKunde(int& nr)
 {
     Kunde* tmpKunde = nullptr;     ///hjelpevariabel
     if (!kundeListe.empty()) {
         nr = lesInt("Kundenummer som skal slettes: ", 1, kundeListe.size());
         if (skrevetUtPaa(nr)) {   //  Kunde finnes i lista:
             auto it = find_if(kundeListe.begin(), kundeListe.end(),
                 [nr](const auto& val) { return(val->hentID() == nr); });
             if (it != kundeListe.end())       //  Fortsatt funn:
                 kundeListe.erase(it);          //  Sletter SELVE PEKEREN.
         }
         cout << "\tSlettet er altså:\n";
       tmpKunde->skrivData();           //  Skriver den som slettes.
         delete tmpKunde;               ///så sletter kunden
     }
 }
 



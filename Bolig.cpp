/**
 *Bolig klassens definisjon, inneholder blant annet:
 *int’er: et unikt oppdrags-/bolignummer, dato innlagt i systemet
 *(på formen ÅÅÅÅMMDD), byggeår, bruttoareal, antall soverom og angitt pris
 *string‘er: navnet på den interne saksbehandleren hos eiendomsfirmaet,
 *nåværende eiers navn, gateadresse (gate+nr), postadresse (nr+sted), og en smålang
 *beskrivelse av boligen ellers (med slikt som: innhold, standard, beliggenhet,
 *tomten, byggemåte, overtagelse, kommunikasjon, avgifter/omkostninger,
 *skole/barnehage, fritidstilbud, ligningsverdi)
 *   @file      BOLIG.CPP
 *   @author    Abdisalan M. Hussein
 */
#include "Bolig.h"
#include "Enebolig.h"
#include "LesData3.h"
#include <iostream>
#include <vector>
#include "enum.h"
#include <fstream>
#include <string>
#include "globaleFunskjoner.h"
using namespace std;



Bolig::Bolig() {
    oppdragsNr      = 0;				
    byggeaar        = 0;
    bruttoAreal     = 0;
    antallSoverom   = 0;
    angittPris      = 0;
   // boligType       = ikkeSatt;
} 

/**
 Leser inn egne datamedlemmer fra brukeren/tastaturet.
*/
void Bolig::lesData() {

    innlagtDato = lesInt("Inlagt dato:\t", 10000000, 99999999);        // dato på format ÅÅÅÅMMDD altså 8-siffer!
    byggeaar = lesInt("Byggeår:\t", 1000, 2020);                       //byggeår fra år 1000 til 2020 i vår tid!
    bruttoAreal = lesInt("Brutto Areal:\t", 1, 100);                   //resten er selvforklarende viljeg håpe!
    antallSoverom = lesInt("Antall soverom:\t", 1, 10);
    angittPris = lesInt("Angitt pris:\t", 1, 900000);
    cout << "Navn paa Sakbehandler:\n";
    getline(cin, navnsaksb);
    cout << "\nNavn paa eier:\n";
    getline(cin, navnEier);
    cout << "\nNavn paa gateadresse: \n";
    getline(cin, gateAdresse);
    cout << "\nNavn paa poststed: \n";
    getline(cin, postAdresse);
    cout << "Bolig beskrivelse:\t";
    getline(cin, boligBeskriv);
}

/**
 *Skriver ut ALLE egne data på skjermen.
*/
void Bolig::skrivData() const {
    cout << "\nOppdragsNr:\t " << oppdragsNr << '\n';
    cout << "BoligType:\t";
    switch (boligType) {
    case bolig: cout << "Bolig\n";       break;
    case enebolig: cout << "Enebolig\n";         break;
    }
    cout << "\nInnlagt Dato:\t " << innlagtDato << '\n';
    cout << "Bygge år:\t " << byggeaar << '\n';
    cout << "Anall Soverom:\t " << antallSoverom << '\n';
    cout << "Bolig Beskrivelse:\t " << boligBeskriv << '\n';
    cout << "\nnederst bolig::skrivdata()\n";
}

/**
* Skriver egne data til fil.    
* @param  ut  - Filobjektet egne data skrives ut til
*/

void Bolig::skrivTilFil(ofstream & ut) {
   
   ut << oppdragsNr << endl << innlagtDato << endl << byggeaar << '\n'
        << bruttoAreal << endl << antallSoverom << endl << angittPris << '\n'
        << navnsaksb << endl << navnEier << endl << gateAdresse << endl
        << postAdresse << endl << boligBeskriv << '\n';

        switch (boligType) {                        
        case bolig:   ut << 'B' << endl;    break; 
        case enebolig:  ut << 'E' << endl;    break;
        default: ut << 'X' << endl;         break;
         }
    
}

/**
* Leser ALLE egne datamedlemmer inn fra fil.
*/
void Bolig::lesFraFil(ifstream& inn)
{
    char tegn;
    inn >> oppdragsNr >> innlagtDato >> byggeaar
        >> bruttoAreal >> antallSoverom >> angittPris; inn.ignore();
    getline(inn, navnsaksb); 
    getline(inn, navnEier);
    getline(inn, gateAdresse);
    getline(inn, postAdresse); 
    getline(inn, boligBeskriv);

    inn >> tegn;
    switch (tegn)
    {
    case 'B': boligType = bolig;    break;
    case 'E': boligType = enebolig; break;

    default: boligType = ikkeSatt;
        break;
    }

}

/**
 *   @file      BOLIG.CPP
 *   @author    Abdisalan M. Hussein
 */
#include "Bolig.h"
#include"Enebolig.h"
#include "LesData3.h"
#include <iostream>
#include <vector>
#include "enum.h"
using namespace std;

Bolig bolig;

Bolig::Bolig() { }

void Bolig::lesData() {

    innlagtDato = lesInt("Inlagt dato:\t", 10000000, 99999999);         // change min max LATER
    byggeår = lesInt("Byggeår:\t", 1000, 2020);
    bruttoAreal = lesInt("Brutto Areal:\t", 1, 100);
    antallSoverom = lesInt("Antall soverom:\t", 1, 10);
    angittPris = lesInt("Angitt pris:\t", 1, 900000);
    navnsaksb = lesChar("Navnet på saksbehandleren:\t");
    navnEier = lesChar("Navnet på nåværende eir:\t");
    gateAdresse = lesChar("GateAdresse + nr:\t");
    postAdresse = lesChar("Post Addresse + nr:\t");
    cout << "Bolig beskrivelse:\t";
    getline(cin, boligBeskriv);
}

/*void Bolig::skrivData() const {
    cout << "OppdragsNr:\t " << oppdragsNr << '\n';
    cout << "BoligType:\t";
    switch (boligtype) {
    case Leilighet: cout << "Leilighet\n";       break;
    case Enebolig: cout << "Enebolig\n";         break;
    }
    cout << "Innlagt Dato:\t " << innlagtDato << '\n';
    cout << "Bygge år:\t " << byggeår << '\n';
    cout << "Anall Soverom:\t " << antallSoverom << '\n';
    cout << "Bolig Beskrivelse:\t " << boligBeskriv << '\n';
}*/

void Bolig::nyOppdrag()
{
    Bolig* nyBolig = nullptr;              //  Peker til nye aktuell ene/bolig.
   // Enebolig* nyEnebolig = nullptr;
    char boligType;                         //  'A' eller 'S'.
                                //  Teller opp og skriver nytt unikt kjørernr:
    cout << "\tNy oppdrag har nr." << ++oppdragsNr << ":\n";

    do {                                     //  Leser ALLTID 'A' eller 'S':
        boligType = lesChar("\tL(eilighet) eller E(nebolig)");
    } while (boligType != 'L' && boligType != 'E');

    switch (boligType) {                    //  Lager en ny aktuell kjører:
    case 'L':  nyBolig = new Bolig(oppdragsNr);     break;
    case 'E':  nyBolig = new Enebolig(oppdragsNr);  break;
    }

    nyBolig->lesData();                   //  Leser kjørerens datamedlemmer.
    
}



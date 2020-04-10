/**
 *   @file      Bolig.cpp
 *   @author    Gruppe 12, NTNU
 */

#include "Bolig.h"
#include"Enebolig.h"
#include "LesData3.h"
#include <iostream>
#include <vector>
#include "enum.h"
#include <fstream>
#include <string>
using namespace std;

Bolig bolig;

Bolig::Bolig() { }

/**
 * Leser Bolig sin data fra brukeren
 */
void Bolig::lesData() {

    innlagtDato = lesInt("Inlagt dato:\t", 1000, 9999);         // change min max LATER
    byggeaar = lesInt("Byggeår:\t", 1000, 2020);
    bruttoAreal = lesInt("Brutto Areal:\t", 1, 100);
    antallSoverom = lesInt("Antall soverom:\t", 1, 10);
    angittPris = lesInt("Angitt pris:\t", 1, 900000);
    cout << "Sakbeh nav:\n";
    getline(cin, navnsaksb);
    getline(cin, navnEier);
    getline(cin, gateAdresse);
    getline(cin, postAdresse);
    cout << "Bolig beskrivelse:\t";
    getline(cin, boligBeskriv);
}

/**
 * Skriver bolig sin data ut på skjermen
 */
void Bolig::skrivData() const {
    cout << "OppdragsNr:\t " << oppdragsNr << '\n';
    cout << "BoligType:\t";
    switch (boligtype) {
    case leilighet: cout << "Leilighet\n";       break;
    case enebolig: cout << "Enebolig\n";         break;
    }
    cout << "Innlagt Dato:\t " << innlagtDato << '\n';
    cout << "Bygge år:\t " << byggeaar << '\n';
    cout << "Anall Soverom:\t " << antallSoverom << '\n';
    cout << "Bolig Beskrivelse:\t " << boligBeskriv << '\n';
}

/**
 * Skriver bolig sin data ut til filen
 * 
 * @param   ut - ofstream referanse variable
 * @file    'SONER.DTA'
 */
void Bolig::skrivTilFil(ofstream & ut) {
   
   ut << oppdragsNr << endl << innlagtDato << endl << byggeaar << '\n'
        << bruttoAreal << endl << antallSoverom << endl << angittPris << '\n'
        << navnsaksb << endl << navnEier << endl << gateAdresse << ' '
        << postAdresse << endl << boligBeskriv << '\n';

        switch (boligtype) {                        
        case leilighet:   ut << "Leilighet";    break; 
        case enebolig:  ut << "Enebolig";    break;
         }
    
}

/**
 * Leser bolig sin data fra filen
 * 
 * @file    'SONER.DTA'
 */
void Bolig::lesFraFil()
{
    ifstream inn("SONER.DTA");
    inn >> oppdragsNr >> innlagtDato >> byggeaar
        >> bruttoAreal >> antallSoverom >> angittPris; inn.ignore();
    getline(inn, navnsaksb); getline(inn, navnEier);
    getline(inn, gateAdresse); getline(inn, postAdresse); getline(inn, boligBeskriv);

}

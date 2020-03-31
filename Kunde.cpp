#include <iostream>
#include <string>
#include <vector>
#include "LesData3.h"
#include "enum.h"
#include "conster.h"
#include "Kunde.h"
#include "Kunder.h"

extern Kunder gkundene;
using namespace std;

Kunde::Kunde() { cout << "Burde aldri komme opp!";}
Kunde::Kunde(int nr) {
    kNr = nr;
    tlf = 0;
}
Kunde::Kunde(ifstream &inn, int nr) {
    inn >> kNr >> tlf; inn.ignore();
    getline(inn,navn);
    getline(inn, mail);
    getline(inn, gate);
    getline(inn, poststed);
    
   // type = lesType();

}   

void Kunde::skrivTilFil(ofstream &utfil){
    
    utfil << kNr        << endl; 
    utfil << tlf        << endl;
    utfil  << navn       << endl;
    utfil << mail        << endl;
    utfil << gate       << endl;
    utfil << poststed << endl;

}
void  Kunde::lesFraFil() {
    ifstream inn("KUNDER.DTA");
    if (inn)        /// sjekker filen åpen/eksisterer
    {
        cout << "Leser fra kunder.dta...";
        inn >> kNr >> tlf >> navn  ; inn.ignore();
    }
}



void Kunde::lesData(){
    int soneNr;
    cout << " \n\tNavn: ";                 getline(cin, navn);
    cout << "\n\tAddresse + nr: ";         getline(cin, gate);
    cout << " \n\tPostaddresse + nr: ";    getline(cin, poststed);
    cout << "\n\t Mail: ";                 getline(cin, mail);
    tlf = lesInt("Telefon Nr: ", 10000000, 99999999); ///8-sifrede telefon
    soneNr = lesInt("Hvilken sone er du interessert initielt: ", 1, maxSoner);
    vKunde.push_back(soneNr); ///ikke helt korrekt?? men egen varibel og bruk hjelpefunsjlon som henter soneNr fra Sone klassen??
    //public hjelpesfundjon i sone som kalles på fra kund si n lesdata().
    }
 
void Kunde::skrivData() {
   // Kunder tmpkunder;       ///gjør akkurat hva den sier
   // tmpkunder.skrivHovedData();
   
    cout << "\n Navn:" << navn << ' '
        << "\nKundenr:" << kNr << ' '
        << tlf << ' ' << mail << ' '
        << gate << ' ' << poststed << '\n';

}

int Kunde::hentID() {
    return kNr;
}
string Kunde::hentNavn() { return navn; }

void Kunde::endreKunde()
{
    char kommando;
    //skriver ut informasjon om hvilke kommandoer som kan velges
    cout << "\nHva har du lyst til aa endre?\n: " << endl
        << "\nTast L for aa legge til,\nTast S for slette sonenummer," << endl
        << "\n velg Q for aa slutte" << endl;
    
    kommando = lesChar("\nTa en valg\n");
    while (kommando != 'Q') {
        switch (kommando) {
        case 'L':

            cout << " \n\tlegg til enda en sone til";
                break;
        case 'S': cout << "Skriv sonen du vil slette";
            break;
        default: break;
        }
        kommando = lesChar("\n\tValg paa nytt?: \n");
    }
}



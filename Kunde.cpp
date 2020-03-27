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
    getline(inn, gate);
    getline(inn, poststed);
    getline(inn, mail);
   // type = lesType();

}   

void Kunde::skrivTilFil(ofstream &utfil){
    
    utfil << kNr        << endl; 
    utfil  << navn       << endl;
    utfil << gate       << endl;
    utfil  << poststed  << endl;
    utfil << tlf        << endl;
    utfil << mail       << endl;





}
void  Kunde::lesFraFil() {
    ifstream inn("KUNDER.DTA");
    if (inn)
    {
        cout << "Leser fra kunder.dta...";
        inn >> kNr >> navn >> tlf; inn.ignore();
    }
}



void Kunde::lesData(){
    cout << " \n\tNavn: ";                 getline(cin, navn);
    cout << "\n\tAddresse + nr: ";         getline(cin, gate);
    cout << " \n\tPostaddresse + nr: ";    getline(cin, poststed);
    cout << "\n\t Mail: ";                 getline(cin, mail);
    tlf = lesInt("Telefon Nr: ", 10000000, 99999999); ///8-sifrede telefon
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
 

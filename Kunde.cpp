#include <iostream>
#include <string>
#include <vector>
#include "LesData3.h"
#include "enum.h"
#include "conster.h"
#include "Kunde.h"

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

void Kunde::skrivTilFil(){
    ofstream utfil("KUNDER.DTA");
   // utfil << kNr        << endl; exception thrown???
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
    void skrivData();

/*int  Kunde::finn(const string nvn) {
    for (unsigned int i = 0; i < navn.size(); i++)
        if (navn[i] == nvn) return (i + 1);     //  Funn!  Returnerer
                                              //  Ikke funn, dvs. ny:
    navn.push_back(nvn);                      //  Legger inn bakerst.
    return navn.size();                       //  Retunerer siste indeks+1 !
}                  //  SORTERER IKKE - ellers vil pasienter bytte indeks !!!

}*/



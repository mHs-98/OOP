
#include <iostream>
#include <string>
#include <vector>
#include "LesData3.h"
#include "enum.h"
#include "conster.h"
#include "Kunde.h"
#include "Kunder.h"
#include "Soner.h"
#include "Sone.h"
#include <string>
#include "globaleFunskjoner.h"

extern Soner gSonene;
using namespace std;

Kunde::Kunde() { cout << "Burde aldri komme opp!";}
Kunde::Kunde(int nr) {

    kNr = nr;
    tlf = 0;
}
Kunde::Kunde(ifstream &inn, int nr) {
    char tegn;
    kNr = nr; inn.ignore();
    getline(inn, navn);
    inn >> tlf; inn.ignore();
    getline(inn, mail);
    getline(inn, gate);
    getline(inn, poststed);
   /* for (auto val : vKunde) {
        val->
    }
   // type = lesType();*/
    inn >> tegn;
    switch (tegn)
    {
    case 'B': boligType = bolig;        break;
    case 'E': boligType = enebolig;      break;
    default: boligType = ikkeSatt;      break;
        break;
    }

}   

void Kunde::skrivTilFil(ofstream &utfil){
    
    utfil << kNr        << endl; 
    utfil << navn       << endl;
    utfil << tlf        << endl;
    utfil << mail       << endl;
    utfil << gate       << endl;
    utfil << poststed    << endl;
   
    switch (boligType) {
    case bolig: utfil << 'B' <<'\n';       break;
    case enebolig: utfil << 'E' << '\n';         break;
    default: utfil << 'X' << '\n';          break;
    }

}

//trenger egenltig ike!
/*void  Kunde::lesFraFil() {
    ifstream inn("KUNDER.DTA");
    if (inn)        /// sjekker filen åpen/eksisterer
    {
        cout << "Leser fra kunder.dta...";
        inn >> kNr; inn.ignore(); getline(inn, navn); inn >> tlf; inn.ignore();
        getline(inn, mail); getline(inn, gate); getline(inn, poststed); inn.ignore();
    }
}*/



void Kunde::lesData() {
    int soneNr;
    char tegn;
    cout << " \n\tNavn: ";                 getline(cin, navn);
    cout << "\n\tAddresse + nr: ";         getline(cin, gate);
    cout << " \n\tPostaddresse + nr: ";    getline(cin, poststed);
    cout << "\n\t Mail: ";                 getline(cin, mail);
    tlf = lesInt("Telefon Nr: ", 10000000, 99999999); ///8-sifrede telefon

    do {
        soneNr = lesInt("Hvilken sone er du interessert initielt: ", 1, maxSoner);
        if (gSonene.finnes(soneNr)) {       //sjekker at sonenummer virkelig fins
            vKunde.push_back(soneNr);       //legger bakerst i vectoren.
        }
        else cout << "Sonenummern finnnes ikke"
            << "tast en sonemmuner mellom 1 og ";
    } while (!gSonene.finnes(soneNr));

    vKunde.push_back(soneNr);

    
    tegn = lesChar("\nSkrvi B eller E\n");
    switch (tegn)
    {
    case 'B': boligType = bolig;        break;
    case 'E': boligType = enebolig;     break;
    default: boligType = ikkeSatt;      break;
        break;
    }


   // type = lesType();
}

 
void Kunde::skrivData() {
   // Kunder tmpkunder;       ///gjør akkurat hva den sier
   // tmpkunder.skrivHovedData();
   
    cout << "\n Navn:" << navn << ' '
        << "\nKundenr:" << kNr << ' '
        << tlf << ' ' << mail << ' '
        << gate << ' ' << poststed << '\n';
    for (auto val : vKunde) {
        cout << val;
    }
    switch (boligType) {
    case bolig: cout << "Bolig" << '\n';       break;
    case enebolig: cout << "Enebolig" << '\n';         break;
    default: cout << "ikkeSatt" << '\n';          break;
    }

}

int Kunde::hentID() {
    return kNr;
}
string Kunde::hentNavn() { return navn; }


void Kunde::hentenKundoversikt(ofstream& ut)
{
    cout << "\ninni kunde::hentekundeoverskit()\n";
    for (auto val : vKunde) {
        if (gSonene.finnes(val)) {
            gSonene.soneforKOversikt(val, ut);

        }
        else
        {
            cout << "\nNoe gikk galt!\n";
        }
        
    }
}


void Kunde::soneEndre()
{
    int soneNr;
    do {
        soneNr = lesInt("Hvilken sone er du interessert aa legge til: ", 1, maxSoner);
         if (gSonene.finnes(soneNr)) {
        vKunde.push_back(soneNr); ///ikke helt korrekt?? men egen varibel og bruk hjelpefunsjlon som henter soneNr fra Sone klassen??
        //public hjelpesfundjon i sone som kalles på fra kund si n lesdata().
          }//
      //  else cout << "Sonenummern finnnes ikke"
          //  << "tast en sonemmuner mellom 1 og ";
         cout << gSonene.finnes(soneNr);
     } while (!gSonene.finnes(soneNr));
     cout << "\nut av while\n";
}
void Kunde::slettSone()
{

    int soneNr;
    do {
        soneNr = lesInt("Hvilken sone er du interessert aa legge til: ", 1, maxSoner);
        if (gSonene.finnes(soneNr)) {//sjekker at sonenummer virkelig finnes
            cout << "\netter if\n";
            auto it = vKunde.begin(); //gaar gjennom vektoren
            cout << "\nforan while\n";
            while (it != vKunde.end())
            {
                if (*it == soneNr)      //peker paa sonenummer som skal slettes
                {
                    vKunde.erase(it);   //sletter den!

                }

            }

        }
        else cout << "Sonenummern finnnes ikke"
            << "tast en sonemmuner mellom 1 og ";
    } while (!gSonene.finnes(soneNr));
}





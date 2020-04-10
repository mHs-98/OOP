/**
 *   @file      Bolig.cpp
 *   @author    Gruppe 12, NTNU
 */

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

extern Soner gSonene;
using namespace std;

/**
 * initialiserer kunde datastrukturen
 */
Kunde::Kunde() { cout << "Burde aldri komme opp!";}
Kunde::Kunde(int nr) {

    kNr = nr;
    tlf = 0;
}

/**
 * Leser kunde sin data fra filen
 * 
 * @param   inn - ifstream referanse variable
 * @file    'KUNDER.DTA'
 */
Kunde::Kunde(ifstream &inn, int nr) {
    cout << "inni kunde-constructor";
    kNr = nr; inn.ignore();
    getline(inn, navn);
    inn >> tlf; inn.ignore();
    getline(inn, mail);
    getline(inn, gate);
    getline(inn, poststed);
    cout << "nederst i constructr";
   // type = lesType();

}   

/**
 * Skriver Kunde sin data ut til filen
 * 
 * @param   ut - ofstream referanse variable
 * @file    'KUNDER.DTA'
 */
void Kunde::skrivTilFil(ofstream &utfil){
    
    utfil << kNr        << endl; 
    utfil << navn       << endl;
    utfil << tlf        << endl;
    utfil << mail       << endl;
    utfil << gate       << endl;
    utfil << poststed    << endl;

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


/**
 * Leser inn kunde sin data fra brukeren
 */
void Kunde::lesData() {
    int soneNr;
    cout << " \n\tNavn: ";                 getline(cin, navn);
    cout << "\n\tAddresse + nr: ";         getline(cin, gate);
    cout << " \n\tPostaddresse + nr: ";    getline(cin, poststed);
    cout << "\n\t Mail: ";                 getline(cin, mail);
    tlf = lesInt("Telefon Nr: ", 10000000, 99999999); ///8-sifrede telefon

    do {
        soneNr = lesInt("Hvilken sone er du interessert initielt: ", 1, maxSoner);
        if (gSonene.finnes(soneNr)) {
            vKunde.push_back(soneNr); ///ikke helt korrekt?? men egen varibel og bruk hjelpefunsjlon som henter soneNr fra Sone klassen??
            //public hjelpesfundjon i sone som kalles på fra kund si n lesdata().
        }
        else cout << "Sonenummern finnnes ikke"
            << "tast en sonemmuner mellom 1 og ";
    } while (!gSonene.finnes(soneNr));
}

/**
 * Skriver Kunde sin innhold
 */
void Kunde::skrivData() {
   // Kunder tmpkunder;       ///gjør akkurat hva den sier
   // tmpkunder.skrivHovedData();
   
    cout << "\n Navn:" << navn << ' '
        << "\nKundenr:" << kNr << ' '
        << tlf << ' ' << mail << ' '
        << gate << ' ' << poststed << '\n';

}

/**
 * hjelpefunskjon som Henter og return kunde Nr
 */
int Kunde::hentID() {
    return kNr;
}
string Kunde::hentNavn() { return navn; }

/*void Kunde::endreKunde()
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
}*/

/**
 * Hjelpe funksjon som får tak i sone Nr en kunde er interessert i
 * 
 * @param   ut - ofstream referanse variable
 * @file    'KUNDER.DTA'
 */
void Kunde::hentenKundoversikt(ofstream& ut)
{
    cout << "\ninni kunde::hentekundeoverskit()\n";
    for (auto val : vKunde) {
        if (gSonene.finnes(val)) {
            gSonene.soneforKOversikt(val, ut);

        }
        else
        {
            cout << "Noe feil!";
        }
        
    }
}

/**
 * Endre Sone sin data
 */
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

/**
 * Slett Sone sin data
 * 
 * @see     Soner::finnes()
 */
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





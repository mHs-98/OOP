/**
 *   @file      Kunde.cpp
 *   @author    Gruppe 12,2020, NTNU
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
#include "globaleFunskjoner.h"

extern Soner gSonene;
using namespace std;


Kunde::Kunde() { cout << "Burde aldri komme opp!";}
/**
 * Constructor initialiserer kunde datastrukturen
 */

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
    char tegn;
    int sonenummer;
    int antall = 0;
    kNr = nr; inn.ignore();
    getline(inn, navn);
    inn >> tlf; inn.ignore();
    getline(inn, mail);
    getline(inn, gate);
    getline(inn, poststed);
    inn >> antall;
    for (int i = 1; i <= antall; i++) {  //  Leser disse navnene:
        inn >> sonenummer;
        vKunde.push_back(sonenummer);             //  Legger BAKERST i vectoren.
    }
  
    inn >> tegn;        //hjelpevariabel
    switch (tegn)
    {
    case 'B': boligType = bolig;        break;
    case 'E': boligType = enebolig;      break;
    default: boligType = ikkeSatt;      break;
        break;
    }

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
    utfil << vKunde.size() << endl;
    for (const auto& val : vKunde)          //  Skriver alle navnene til fil:
        utfil << val << '\n';
    switch (boligType) {
    case bolig: utfil << 'B' <<'\n';       break;
    case enebolig: utfil << 'E' << '\n';         break;
    default: utfil << 'X' << '\n';          break;
    }

}

/**
 * Leser inn kunde sin data fra brukeren/tastaturet
 */
void Kunde::lesData() {
    int soneNr;
    char tegn;
    cout << " \n\tNavn: ";                 getline(cin, navn);
    cout << "\n\tAddresse + nr: ";         getline(cin, gate);
    cout << " \n\tPostaddresse + nr: ";    getline(cin, poststed);
    cout << "\n\t Mail: ";                 getline(cin, mail);
    tlf = lesInt("Telefon Nr: ", 10000000, 99999999);           //8-sifrede telefon

    do {
        soneNr = lesInt("Hvilken sone er du interessert initielt: ", 1, maxSoner);
       
    } while (!gSonene.finnes(soneNr));

    vKunde.push_back(soneNr);               //legger sonenumeren inni 'DEN' kundens intersesone(vctor)

    
    tegn = lesChar("\nSkrvi (B)olig eller (E)nebolig");
    switch (tegn)
    {
    case 'B': boligType = bolig;        break;
    case 'E': boligType = enebolig;     break;
    default: boligType = ikkeSatt;      break;
        break;
    }
}

/**
 * Skriver Kundens data til skjermen
 */
void Kunde::skrivData() {
 
   cout << "\nKundenr:" << kNr << ' '
    << "\n Navn:" << navn << ' '
        << tlf << ' ' << mail << ' '
        << gate << ' ' << poststed << '\n';
   cout << " \tInteresserte Soner:\t ";
  for (const int  &val : vKunde) {
       cout << val << " ";
   }

  switch (boligType) {
    case bolig: cout << "\tBoligtype: Bolig" << '\n';       break;
    case enebolig: cout << "\tBoligtype: Enebolig" << '\n';         break;
    default: cout << "\nikkeSatt" << '\n';          break;
    }

}

/*
*Hjelpefunkjon som returnere kundernummer
*/
int Kunde::hentID() {
    return kNr;
}
/*
*Hjelpefunskjon som returnerer kundenavnet
*/
string Kunde::hentNavn() { 
    return navn; 
}

/*
*går gjennom alle kundene, og for hver kunde sjekkes om de er interesser det sonen
*@ see Soner::soneforKOversikt(...)
*@ see Soner::finnes(...)
*/
void Kunde::hentenKundoversikt(ofstream& ut)
{
 
    for (auto val : vKunde) {                          //gaa gjennoom alle kundene
        if (gSonene.finnes(val)) {                     //for hver kunde sjekk om de har vist interesse for sonen "val"
            gSonene.soneforKOversikt(val, ut);         //kaller paa funksjonen som fullfører løpet videre!

        }
        else
        {
            cout << "\nNoe gikk galt!\n";
        }
        
    }
}

/*
*Tilbyr kunden å endre sonen altså legge til enda en sone til
*@see   Soner::finnes(...)
*
*/
void Kunde::soneEndre()
{
    int soneNr;
    do {
        soneNr = lesInt("Hvilken sone er du interessert aa legge til: ", 1, maxSoner);
      
    } while (!gSonene.finnes(soneNr));      //sikrer at sonen faktisk finnes/eksisterer
    vKunde.push_back(soneNr);               //legger sonen inni DEN kundens butikk!
    }


/*
*Sletter sone fra en Kunde's butikk
*@see       Soner::finnes(...)
*/
void Kunde::slettSone()
{

    int soneNr;
    do {
        soneNr = lesInt("Hvilken sone er du interessert aa legge til: ", 1, maxSoner);
        if (gSonene.finnes(soneNr)) {           //sjekker at sonenummer virkelig finnes
            auto it = vKunde.begin();           //gaar gjennom vektoren
            cout << "\nforan while\n";
            while (it != vKunde.end())
            {
                if (*it == soneNr)      //peker paa riktig sonenummer som skal slettes
                {
                    vKunde.erase(it);   //sletter den!

                }

            }

        }
        else cout << "Sonenummern finnnes ikke"
            << "tast en sonemmuner mellom 1 og ";
    } while (!gSonene.finnes(soneNr));
}





#include <iostream>
#include <fstream>
#include "LesData3.h"
#include "Soner.h"
#include "Sone.h"
#include "conster.h"
#include "Bolig.h"
#include <map>
#include "Enebolig.h"

extern Soner gsonene;
//extern Bolig boliger;

using namespace std;

/**
 * Leser inn klassens innhold fra filen
 * @param in - Filobjektet egne data leses inn fra
 */ 
Sone::Sone(ifstream & in) {
    getline(in, soneBeskrivelse);
}

/**
 * 
 * 
 */ 
void Sone::skrivTilFil(ofstream & ut) const {
    ut << unikSNr << "\t" << soneBeskrivelse << endl;
}

void Sone::lesBeskrivelse() {
    cout << "\n\nSkriv en kort beskrivelse om sonen: ";
    getline(cin, soneBeskrivelse); //Leser inn sonens beskrivelse

}
Sone::Sone(int nr) {
    unikSNr = nr;
     soneBeskrivelse = "Eksempel Beskrivelse";
};

void Sone::skrivData() {
    cout << "\t";
    cout << "\n\tSone Nr: " << unikSNr
        << "\tBeskrivelse: " << soneBeskrivelse;

}

/// @todo: Lage Bolig::skrevetPaa() i Bolig.h
void Sone::skrivEnSone(int sNr) { // g gjennom boliger og skrive ut en bolig
    /*if (!gBoliger.empty()) {
        sNr = lesInt("Sone nr: ", 1, maxSoner);
        for (const auto val : gBoliger) {
            if (val.second->skrevetUtPaa(sNr)) {
                val.second->skrivEnOppdrag(sNr);
                if ( (sNr % 5) != 0) {
                cout << "\n\n\tTrykk Paa ENTER for  fortsette";
                cin.get();
            }
            }
        }

    }
    else
    {
        cout << "\n\tIngen data av Soner fantes!\n\n";
    }
    */
}

void Sone::lagnyOppdrag(int nr)
{
    Bolig* nyBolig = nullptr;
   // nyBolig->nyOppdrag();       //kaller paa funskjone i bolig klassen
                                  //veldig knotete aa gjøre det paa men, maa man saa man!

    char boligType;

    do {                                     //  Leser ALLTID 'A' eller 'S':
        boligType = lesChar("\tL(eilighet) eller E(nebolig)");
    } while (boligType != 'L' && boligType != 'E');

    switch (boligType) {                    //  Lager en ny aktuell kjører:
    case 'L':  nyBolig = new Bolig(nr);     break;
    case 'E':  nyBolig = new Enebolig(nr);  break;
    }

    nyBolig->lesData();
    gBoliger.push_back(nyBolig);//ny oppdraget legges bakerst i vektoren
}

/*void Sone::nyOppdrag(int& snNr)
{
    Bolig*      nyBolig      = nullptr;              //  Peker til nye aktuell ene/bolig.
    
    do {
        snNr = lesInt("Hvilken sone skal oppdraget opprettes i: ", 1, maxSoner);
        if (gsonene.finnes(snNr)) {
            nyBolig->nyOppdrag();       //kaller på nyOppdrag fra Bolig
            gBoliger.push_back(nyBolig); 
        }
        else cout << "Sonenummern finnnes ikke"
            << "tast en sonemmuner mellom 1 og ";
    } while (!gsonene.finnes(snNr));
}*/

#include <iostream>
#include <fstream>
#include "LesData3.h"
#include "Soner.h"
#include "Sone.h"
#include "conster.h"
#include "Bolig.h"
#include <map>
#include "Enebolig.h"
#include "enum.h"
#include "globaleFunskjoner.h"
#include <string>

extern Soner gsonene;
//extern Bolig boliger;

using namespace std;

/**
 * Leser inn klassens innhold fra filen
 * @param in - Filobjektet egne data leses inn fra
 */ 
Sone::Sone(int snr,  ifstream& in) {
    unikSNr = snr;
    Bolig* enBolig = nullptr;
    int i;
   
        getline(in, soneBeskrivelse);
        in >> i;
        for (; i > 0; i--) {
            enBolig = new Bolig();
           enBolig->lesFraFil(in);
            gBoliger.push_back(enBolig);
        }
}

Sone::Sone(int nr) {
    unikSNr = nr;
    soneBeskrivelse = "Eksempel Beskrivelse";
};


/**
 * 
 * 
 */ 
void Sone::skrivTilFil(ofstream & ut)  {
        ut << unikSNr << "\t" << soneBeskrivelse << endl;
        ut << gBoliger.size() << endl;
   for (auto val : gBoliger) {
        val->skrivTilFil(ut);
    }
}

void Sone::lesBeskrivelse() {
    cout << "\n\nSkriv en kort beskrivelse om sonen: ";
    getline(cin, soneBeskrivelse); //Leser inn sonens beskrivelse

}

void Sone::skrivData() {
    //gp gjennm alle boliger og la hver bolig hente sin siz()
    
    ///Bolig bolig;
    cout << "\t";
    cout << "\n\tSone Nr: " << unikSNr
        << "\tBeskrivelse: " << soneBeskrivelse;
    cout << " Saa mange boliger finnes:" << gBoliger.size();
    
    
    /* bolig.skrivData();
    cout << "\nnederst sone::skrivData()";
    */
}

/// @todo: Lage Bolig::skrevetPaa() i Bolig.h
void Sone::skrivEnSone(int sNr) { // g gjennom boliger og skrive ut en bolig
   
    for (auto val : gBoliger) {
        val->skrivData();
    }
}





   /* if (!gBoliger.empty()) {
        sNr = lesInt("Sone nr: ", 1, maxSoner);
        for (const auto val : gBoliger) {
            if (val->hentID->skrevetUtPaa(sNr)) {
                val->hentID->skrivEnOppdrag(sNr);
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
    
}*/

void Sone::lagnyOppdrag(int nr)
{
    Bolig *nyBolig = nullptr;
 
     //boligtype type;
   
    //const Boligtype type = lesType();
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

void Sone::enOppdrag(int nr)
{
    for (auto val : gBoliger) { //lop alle oppdragr
        if(nr ==val->hentID())        // hvis riktgi opdranummer
            val->skrivData();   //skriv sin egen data?
    }

}

void Sone::enkundeoversikt(ofstream& ut)
{
    
    for (auto val : gBoliger) {
        val->skrivTilFil(ut);
    }

}

void Sone::hjelpeKA()
{
    for (auto val : gBoliger) {
        val->skrivData();
    }
}


/**
 *   @file      Sone.cpp
 *   @author    Gruppe 12, NTNU 2020
 */
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
#include <algorithm>

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
/**
 * Intialerer Eksempel Sone
 *
 * @param   nr - Sone Nr
 */
Sone::Sone(int nr) {
    unikSNr = nr;
    soneBeskrivelse = "Eksempel Beskrivelse";
};


/**
**
 * Skriver ut klassens innhold til filen
 *@see      Bolig::skrivTilFil(...)
 * @param   in - Filobjektet egne data leses inn fra
 */
void Sone::skrivTilFil(ofstream & ut)  {
        ut << unikSNr << " " << soneBeskrivelse << endl;
        ut << gBoliger.size() << endl;
   for (auto val : gBoliger) {
       if (val != nullptr) {            //hvis oppdrag ikke tom (ekstra viktig for at slett oppdrag skal funke ellers blir read-violation access!)
           val->skrivTilFil(ut);        //be om aa skrive seg til fil!
       }
    }
}
/**
 * Leser Sonens beskrivelse
 */
void Sone::lesBeskrivelse() {
    cout << "\n\nSkriv en kort beskrivelse om sonen: ";
    getline(cin, soneBeskrivelse); //Leser inn sonens beskrivelse
}

/**
 * Skriver hver Sone sin data til skjerm
 */
void Sone::skrivData() {
    cout << "\t";
    cout << "\n\tSone Nr: " << unikSNr
        << "\tBeskrivelse: " << soneBeskrivelse;
    cout << "\n\tSaa mange boliger finnes:\t" << gBoliger.size() << '\n';
}

/**
*Går gjennom boliger i en Sone og skriver alt om dem
*
* @see     Boliger::skrivData()
* */
void Sone::skrivEnSone(int sNr) { // gaa gjennom boliger og skrive ut en bolig

    int tmp = 0;
    for (auto val : gBoliger) {
        val->skrivData();
        tmp++;
        if ((tmp % 5) == 0) {              //stans utskriften for hver 5.utskrift!
            cout << "\n\n\tTrykk Paa ENTER for  fortsette";
            cin.get();
        }
    }
}
    


/**
 * Lager ny oppdrag og legger den inn i datastrukturen
 *
 * @param   nr - Sone Nr
 * @see      Bolig::Bolig(...)
 * @see     Bolig::lesData()
 * @see      Enebolig::Enebolig(...)
 */

void Sone::lagnyOppdrag(int nr)
{
    Bolig* nyBolig = nullptr;

     char boligType;

     do {                                     //  Leser ALLTID 'B' eller 'E':
           boligType = lesChar("\tB(eilighet) eller E(nebolig)");
       } while (boligType != 'B' && boligType != 'E');
      
    
        switch (boligType) {                    //  Lager en ny aktuell ene/bolig:
        case 'B':  nyBolig = new Bolig(nr);     break;
        case 'E':  nyBolig = new Enebolig(nr);  break;
        }

        nyBolig->lesData();                 //hver oppdrag leser inn sin egen data
        gBoliger.push_back(nyBolig);        //ny oppdraget legges bakerst i vektoren
   
}

/**
*Går gjennom alle oppdrag og skriver en spesifikk oppdrags sin data
* @see      Bolig::hentID()
* @see      Bolig::skrivData()
* @param   nr - Sone Nr
* */
void Sone::enOppdrag(int nr)
{
    for (auto val : gBoliger) { //lop alle oppdragr
        if(nr ==val->hentID())        // hvis riktgi opdranummer
            val->skrivData();   //skriv sin egen data?
    }

}

/**
 * Skriver en kunde sin Sone og boliger innhold
 *
 * @param   ut - ofstream referanse variable
 * @see     Bolig::skrivTilFil()
 */
void Sone::enkundeoversikt(ofstream& ut)
{
    
    for (auto val : gBoliger) {
        val->skrivTilFil(ut);
    }

}


/**
 * Sletter spesifikk oppdrag fra datastrukturen
 *
 * @param   nr - Sone Nr
 * @see     Bolig::hentID()
 */
void Sone::slettEnOppdrag(int nr)
{
    int i = 0;
    for (auto it = gBoliger.begin(); it != gBoliger.end(); it++, i++) {

        if ((*it)->hentID() == nr) {
            cout << "\n\tØnsker du VIRKELIG å slette/fjerne "
                << "ALLE disse denne";
            if (lesChar(" (j/N)") == 'J') {      //  VIL slette alle:

                delete(*it);            //slett selve pekern
                *it = NULL;             //og sett den NULL(nullptr funket ikke! fikke read access vioalation)
                gBoliger.erase(it);     //nå kan vi slette selve oppdraget!

                return;
            }
        }


    }
}



/**
 *   L�sningsforslag - Gruppe12, Prosjekt i OOProg v2020 (PROG1003)
 *
 *   Programmet holder orden p� oppdrag/ boliger  til salgs 
 *   i ulike soner i en by/et geografisk omr�de, samt 
 *   potensielle kunder/kj�pere som har interesse for boliger 
 *   i en eller flere av disse sonen
 *
 *
 *   @file     MAIN.CPP
 *   @author   Mohamed Said, Abdisalan Hussein, Elias Touil, NTNU Studenter.
 */

#include <iostream>
#include "globaleFunskjoner.h"
#include "LesData3.h"                   //  Verkt�ykasse for lesing av diverse data
#include "Kunde.h"                      //  'Kundebase'
#include "Kunder.h"                     //  'Kunderbase'
#include "Soner.h"                      //  'Sonerbase'


using namespace std;


Soner gSonene;              ///<  Datastrukturen med ALLE Kunder.
Kunder gkundene;                ///<  Datastrukturen med ALLE Soner.


/**
 *  Hovedprogrammet:
 */
int main(){
    char valg;



    gSonene.lesFraFil();


    gkundene.lesFraFil();
    
    skrivMeny();

        valg = lesChar("\nValg en handling: ");


    while(valg != 'Q'){
        switch(valg){
            case 'K': gkundene.KundeHandling();   break;
            case 'S': case 'O':
                gSonene.soneHandling(valg);    break;
            default: skrivMeny();

        }valg = lesChar("Vagl p� nytt?");
    }
    gkundene.skrivTilFil();
    gSonene.skrivTilFil();
return 0;
}

     


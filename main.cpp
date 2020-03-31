#include <iostream>
#include "globaleFunskjoner.h"
#include "LesData3.h"
#include "Kunde.h"
#include "Kunder.h"
#include "Soner.h"
#include "Sone.h"

using namespace std;

Soner gsonene;
Soner gSoner;
Kunder gkundene;


int main(){

char valg;
    //gsonene.lesFrafil();
    gkundene.lesFraFil();

    skrivMeny();

    valg = lesChar("Valg en handling");

    while(valg != 'Q'){
        switch(valg){
            case 'K': gkundene.KundeHandling();   break;
            case 'S': case 'O':
                gsonene.soneHandling();    break;

                gSoner.soneHandling();    break;
            default: skrivMeny();

        }valg = lesChar("Valg på nytt?");
    }
    gkundene.skrivTilFil();
return 0;
}

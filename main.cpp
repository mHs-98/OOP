#include <iostream>
#include "globaleFunskjoner.h"
#include "LesData3.h"
#include "Kunde.h"
#include "Kunder.h"
#include "Soner.h"

using namespace std;

Soner gSonene;
Kunder gkundene;


int main(){

char valg;
    gSonene.lesFraFil();
    gkundene.lesFraFil();

    skrivMeny();

    valg = lesChar("Valg en handling");

    while(valg != 'Q'){
        switch(valg){
            case 'K': gkundene.KundeHandling();   break;
            case 'S': case 'O':
                gSonene.soneHandling();    break;
            default: skrivMeny();

        }valg = lesChar("Vagl på nytt?");
    }
    gkundene.skrivTilFil();
    gSonene.skrivTilFil();
return 0;
}

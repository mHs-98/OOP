#include<string>
#include<iostream>
#include "globaleFunskjoner.h"

using namespace std;

void skrivMeny(){
    cout << "\nVelg 'K'under eller 'S'oner:\n";
    cout << " \t For aa komme til Kunde-omraade eller Sone-omraade\n";


}

Boligtype lesType()
{       char type;

do {                         //  Leser ALLTID  'L' eller 'E':
    type = lesChar("\tGjenstand-type (E)enebolig, (L)eiglighet");
} while (type != 'E' && type != 'L');

        switch (type) {             //  Gjør om til og returnerer aktuell type:
        case 'E':  return enebolig; break;
        case 'B':  return bolig; break;
        }
        return ikkeSatt;            //  Skal ALDRI kunne skje (da sikrer(?!!!)
    }                               //    ovenfor at ER BARE 'E', eller 'L').

    


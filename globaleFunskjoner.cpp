/***
* @file      Enebolig.CPP
* @author    Gruppe 12, 2020
**/

#include<string>
#include<iostream>
#include "globaleFunskjoner.h"

using namespace std;

/**
*Skriver meny/muligheter til skjerm
*/
void skrivMeny(){
    cout << "\nVelg 'K'under eller 'S'oner eller 'O'ppdrag:\n";
    cout << " \t For aa komme til Kunde-omraade eller Sone-omraade\n";


}
/**
*leser inn type bolig/enebolig og fyller enum med riktig data
*/
Boligtype lesType()
{
    char type;

    do {                         //  Leser ALLTID  'L' eller 'E':
        type = lesChar("\tGjenstand-type (E)enebolig, (L)eiglighet");
    } while (type != 'E' && type != 'L');

    switch (type) {             //  Gjør om til og returnerer aktuell type:
    case 'E':  return enebolig; break;
    case 'B':  return bolig; break;
    }
    return ikkeSatt;
}

    


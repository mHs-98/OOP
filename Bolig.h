#pragma once
#ifndef __BOLIG_H                  //  Ensures that this file will be
#define __BOLIG_H                  //  included only ONCE in each file

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "LesData3.h"

using namespace std;


class Bolig {

private:
    int oppdragNr;
    string  saksbehandler,
            eierNavn,
            addresse,
            beskrivelse;
public:
    Bolig();
    Bolig(ifstream &inn);
};

#endif
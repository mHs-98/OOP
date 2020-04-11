/**
*Enebolig.h, deklerasjonsklassen
*@author: Abdisalan M. Husein, Mahamed Hassan Said, Elias Touil, NTNU Gjøvik
*@file: Enebolig.h.
*
*/


#ifndef __ENEBOLIG_H
#define __ENEBOLIG_H

#include <string>
#include "Bolig.h"


class Enebolig : public Bolig {
private:
	int areal;				// Tomtens areal i kvadratmeter.
	bool festetomt;			// som tomten er selveiet eller ei(festetomt)

public:
	Enebolig() { areal = 0; festetomt = false; };
	Enebolig(const int nr);
	void	lesData();
	void	skrivData();
	void	skrivTilFil(std::ofstream& ut);
	~Enebolig();
};


#endif
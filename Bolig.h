/**
*	Bolig.h, deklerasjonsklassen
*
*	@file		BOLIG.H
*	@author		Abdisalan M. Husein, Mahamed Hassan Said, Elias Touil, NTNU Gjøvik
*
*/

#ifndef __BOLIG_H
#define __BOLIG_H

#include <string>
#include <iostream>
#include <fstream>
#include "enum.h"
#include <string>

/**
 *  Bolig Klasse
 */

class Bolig {
private:
	int oppdragsNr,					// et unikt oppdrags-/bolignummer
		innlagtDato,				// Inlagt dato i systemet
		byggeaar,
		bruttoAreal,
		antallSoverom,
		angittPris;

	std::string navnsaksb,			// Navnet på interne saksbehandleren hos eiendomsfirmaet.
		navnEier,					// Navnet på nåværende eir
		gateAdresse,				// gate + nr
		postAdresse,				// postnumber + sted
		boligBeskriv;				//		LATER
	
protected:

	Boligtype boligType;
public:
	Bolig();
	Bolig(const int nr) {
		oppdragsNr = nr; 
		boligType = bolig;
	};
	int		hentID() { return oppdragsNr; }
	void	lesData();
	void	skrivData() const;
	void	skrivTilFil(std::ofstream & ut);
	void	lesFraFil(std::ifstream& inn);

};

#endif
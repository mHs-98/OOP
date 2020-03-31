#ifndef __BOLIG_H
#define __BOLIG_H
#include <string>
#include "enum.h"


class Bolig {
private:
	int oppdragsNr,					// et unikt oppdrags-/bolignummer
		innlagtDato,				// Inlagt dato i systemet
		bygge�r,
		bruttoAreal,
		antallSoverom,
		angittPris;

	std::string navnsaksb,			// Navnet p� interne saksbehandleren hos eiendomsfirmaet.
		navnEier,					// Navnet p� n�v�rende eir
		gateAdresse,				// gate + nr
		postAdresse,				// postnumber + sted
		boligBeskriv;				//		LATER
	boligtype boligtype;

public:
	Bolig();
	Bolig(const int nr) { oppdragsNr = nr; };
	int		hentID() { return oppdragsNr; }
	void	lesData();
	void	skrivData() const;
	void nyOppdrag();
};

#endif
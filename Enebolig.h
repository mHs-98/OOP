#ifndef __ENEBOLIG _H
#define __ENEBOLIG_H
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
		~Enebolig();
};


#endif
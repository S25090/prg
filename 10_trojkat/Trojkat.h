#include "RodzajTrojkata.h"

class Trojkat
{
private:
	int const a;
	int const b;
	int const c;

	int znajdzNajdluzszyBok() const;
	bool czyTrojkat() const;
	RodzajTrojkata jakiTrojkat() const;

public:
	Trojkat(int a, int b, int c);
	void sprawdz() const;
	
};


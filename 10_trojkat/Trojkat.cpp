
#include <iostream>
#include "Trojkat.h"
#include "RodzajTrojkata.h"
#include <cmath>



Trojkat::Trojkat(int a, int b, int c) :
a{ a },
b{ b },
c{ c }
{};

void Trojkat::sprawdz() const
{
	if (czyTrojkat() == false)
	{
		std::cout << "Z podanych dlugosci bokow: " << a << ", " << b << ", " << c << " nie da sie stworzyc trojkata." << std::endl;
		return;
	}
	
	RodzajTrojkata rodzaj = jakiTrojkat();

	if (rodzaj == RodzajTrojkata::PROSTOKATNY)
	{
		std::cout << "To jest trojkat prostokatny o bokach: " << a << ", " << b << ", " << c << std::endl;
	}
	else if (rodzaj == RodzajTrojkata::ROZWARTOKATNY)
	{
		std::cout << "To jest trojkat rozwartokatny o bokach: " << a << ", " << b << ", " << c << std::endl;
	}
	else
	{
		std::cout << "To jest trojkat ostrokatny o bokach: " << a << ", " << b << ", " << c << std::endl;
	}

};

int Trojkat::znajdzNajdluzszyBok() const
{
	int najdluzszyBok = a;

	if (b > najdluzszyBok)
	{
		najdluzszyBok = b;
	}

	if (c > najdluzszyBok)
	{
		najdluzszyBok = c;
	}
	return najdluzszyBok;
}

bool Trojkat::czyTrojkat() const
{
	int najdluzszyBok = znajdzNajdluzszyBok();
	
	if (najdluzszyBok == a)
	{
		if (b + c > najdluzszyBok)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if (najdluzszyBok == b)
	{
		if (a + c > najdluzszyBok)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if (najdluzszyBok == c)
	{
		if (a + b > najdluzszyBok)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

RodzajTrojkata Trojkat::jakiTrojkat() const
{
	int najdluzszyBok = znajdzNajdluzszyBok();
	RodzajTrojkata rodzaj;

	if (najdluzszyBok == a)
	{
		if (pow(b, 2) + pow(c, 2) == pow(najdluzszyBok, 2))
		{
			rodzaj = RodzajTrojkata::PROSTOKATNY;
		}
		else if (pow(b, 2) + pow(c, 2) < pow(najdluzszyBok, 2))
		{
			rodzaj = RodzajTrojkata::ROZWARTOKATNY;
		}
		else
		{
			rodzaj = RodzajTrojkata::OSTROKATNY;
		}
	}

	if (najdluzszyBok == b)
	{
		if (pow(a, 2) + pow(c, 2) == pow(najdluzszyBok, 2))
		{
			rodzaj = RodzajTrojkata::PROSTOKATNY;
		}
		else if (pow(a, 2) + pow(c, 2) < pow(najdluzszyBok, 2))
		{
			rodzaj = RodzajTrojkata::ROZWARTOKATNY;
		}
		else
		{
			rodzaj = RodzajTrojkata::OSTROKATNY;
		}
	}
	
	if (najdluzszyBok == c)
	{
		if (pow(a, 2) + pow(b, 2) == pow(najdluzszyBok, 2))
		{
			rodzaj = RodzajTrojkata::PROSTOKATNY;
		}
		else if (pow(a, 2) + pow(b, 2) < pow(najdluzszyBok, 2))
		{
			rodzaj = RodzajTrojkata::ROZWARTOKATNY;
		}
		else
		{
			rodzaj = RodzajTrojkata::OSTROKATNY;
		}
	}
	
	return rodzaj;
}

#include <iostream>
#include "Kontakt.h"

Kontakt::Kontakt(int numerTelefonu, std::string nazwisko, int liczbaPolaczen) :
	numerTelefonu{numerTelefonu},
	nazwisko{nazwisko},
	liczbaPolaczen{liczbaPolaczen}
{
}

void Kontakt::wypiszKontakt()
{
	std::cout << "numer telefonu: " << numerTelefonu << std::endl;
	std::cout << "nazwisko: " << nazwisko << std::endl;
	std::cout << "liczbaPolaczen: " << liczbaPolaczen << std::endl;
}

int Kontakt::dajNumerTelefonu()
{
	return numerTelefonu;
}

void Kontakt::zwiekszLiczbePolaczen()
{
	liczbaPolaczen++;
}

std::string Kontakt::dajNazwisko()
{
	return nazwisko;
}
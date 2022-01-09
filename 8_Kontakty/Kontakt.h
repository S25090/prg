#include <string>

#ifndef KONTAKT_H
#define KONTAKT_H

class Kontakt
{
private:
	int numerTelefonu;
	std::string nazwisko;
	int liczbaPolaczen;

public:
	Kontakt(int numerTelefonu, std::string nazwisko, int liczbaPolaczen);
	Kontakt() = default;

	void wypiszKontakt();
	int dajNumerTelefonu();
	void zwiekszLiczbePolaczen();
	std::string dajNazwisko();
};

#endif
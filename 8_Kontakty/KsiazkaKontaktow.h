#include <vector>
#include "Kontakt.h"

#ifndef KSIAZKA_KONTAKTOW_H
#define KSIAZKA_KONTAKTOW_H

class KsiazkaKontaktow
{

public:
	std::vector<Kontakt> kontakty;
	void wypiszMenu();
	void wypiszKontakty();
	bool wyszukajKontakt(int numerTelefonu, Kontakt& kontakt);
	void dodajNumer(int numer, std::string nazwisko);
	bool usunKontakt(int numerTelefonu);
	bool polacz(std::string nazwisko);
};

#endif

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "Pacjent.h"

#ifndef REJESTR_PACJENTOW_H
#define REJESTR_PACJENTOW_H

class RejestrPacjentow
{
private:
	std::vector <Pacjent> rejestr;
	Pacjent zalogowanyPacjent;
	bool czyLiczba(const std::string& s);
	bool kontrolaDaty(std::string data);

public:
	void rejestruj(Pacjent pacjent);
	void zaloguj(std::string login, std::string haslo);
	bool czyZalogowany;
	void wyloguj();
	void wyswietlMenuZalogowany();
	void wypiszDaty();
	void zaszczep(std::string data);
	void wyswietlMenu();
	bool czyMogeZaszczepic();
	std::string currentDate();
	int liczbaDni(int rok1, int miesiac1, int dzien1, int rok2, int miesiac2, int dzien2);
	std::tm make_tm(int year, int month, int day);
	int DajLiczbeDniOdSzczepienia(std::string dataSzczepienia);
	void ObslugaMenuZalogowany();
	bool czyWaznyCertyfikat();
	
};

#endif
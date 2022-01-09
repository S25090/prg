#include <string>
#include <ctime>
#include <vector>

#ifndef PACJENT_H
#define PACJENT_H

struct Pacjent
{
	std::string login;
	std::string haslo;
	std::string imie;
	std::string nazwisko;
	std::vector <std::string> datySzczepien;
	
	Pacjent(std::string login, std::string haslo, std::string imie, std::string nazwisko);
	Pacjent() = default;
};

#endif
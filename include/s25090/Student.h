#ifndef STUDENT_H 
#define STUENT_H

#include <string>

struct Student
{
	std::string const imie;
    std::string const nazwisko;
	std::string const numer_indeksu;
	int aktualny_semestr;
	float srednia_ocen;

	Student ( std::string imie, std::string nazwisko, std::string numer_indeksu, int aktualny_semestr, float srednia_ocen );
    std::string to_string() const;
};
#endif

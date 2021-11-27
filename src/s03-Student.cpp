#include <iostream>
#include "../include/s25090/Student.h"

auto main() -> int
{

	Student student = Student("Alicja","Wosik", "s25090" ,1, 4.25);


	std::cout << "student.to_string() = " << student.to_string() << std::endl;


	return 0;
}


Student::Student ( std::string pImie, std::string pNazwisko, std::string pNumer_indeksu, int pAktualny_semestr, float pSrednia_ocen ) 
	: imie{pImie}, nazwisko{pNazwisko}, numer_indeksu{pNumer_indeksu}
{
	aktualny_semestr = pAktualny_semestr;
	srednia_ocen = pSrednia_ocen;	
}

std::string Student::to_string() const
{

	std::string s1 ("imie: " + imie + " nazwisko: " + nazwisko + " numer_indeksu: " + numer_indeksu + " aktualny_semestr: " + std::to_string(aktualny_semestr) + " srednia_ocen: " + std::to_string(srednia_ocen) );
	return s1;

}

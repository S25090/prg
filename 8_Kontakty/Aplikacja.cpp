#include "Kontakt.h"
#include "KsiazkaKontaktow.h"
#include <iostream>
#include <string>

int main()
{
    KsiazkaKontaktow ksiazkaKontaktow;

   /* ksiazkaKontaktow.dodajNumer(669, "Kowalski");
    ksiazkaKontaktow.dodajNumer(145, "Nowak");
    ksiazkaKontaktow.dodajNumer(887, "Lewandowski");*/

     Kontakt znaleziony;

     if (ksiazkaKontaktow.wyszukajKontakt(669, znaleziony))
     {
         std::cout << "Znaleziono kontakt: " << std::endl;
         znaleziony.wypiszKontakt();
     }

    int wybor;
    int numer;
    std::string nazwisko;
    

    while (true)
    {
        ksiazkaKontaktow.wypiszMenu();
        std::cin >> wybor;

        switch (wybor)
        {
        case 1:
            {
                std::cout << "Podaj numer: ";
                std::cin >> numer;

                Kontakt kontakt;
                if (ksiazkaKontaktow.wyszukajKontakt(numer, kontakt))
                {
                    std::cout << "Znaleziono kontakt: " << std::endl;
                    kontakt.wypiszKontakt();
                }
                else
                {
                    std::cout << "Brak kontaktu o tym numerze!" << std::endl;
                }
                std::cout << std::endl;
                break;
            }
        case 2:
            {
                std::cout << "Podaj numer: ";
                std::cin >> numer;
                std::cout << "Podaj nazwisko: ";
                std::cin >> nazwisko;
                ksiazkaKontaktow.dodajNumer(numer, nazwisko);
                std::cout << std::endl;
                break;
            }
        case 3:
            {
                std::cout << "Podaj numer: ";
                std::cin >> numer;
                if (ksiazkaKontaktow.usunKontakt(numer) == false)
                {
                    std::cout << "Brak kontaktu o takim numerze!" << std::endl;
                    std::cout << std::endl;
                }
                break;
            }
        case 4:
            {
                std::cout << "Podaj nazwisko: ";
                std::cin >> nazwisko;
                ksiazkaKontaktow.polacz(nazwisko);
                std::cout << std::endl;
                break;
            }
        case 5:
            {
                ksiazkaKontaktow.wypiszKontakty();
                std::cout << std::endl;
                break;
            }
        case 0:
            {
                exit(0);
                break;
            }
        default:
            {
                std::cout << "Dostepne sa tylko opcje 0-5" << std::endl;
                std::cout << std::endl;
                break;
            }
        }
    }
    
    return 0;
}
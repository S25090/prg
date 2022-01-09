
#include <iostream>
#include <string>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include "Slownik.h"


int main()
{
    Slownik slownik = Slownik();

   /* slownik.dodajSlowo("ala");
    slownik.dodajSlowo("ola");
    slownik.dodajSlowo("hela");
    slownik.dodajSlowo("ania");*/

    int wybor;
    std::string slowo;

    while (true)
    {
        slownik.napiszMenu();
        std::cin >> wybor;

        switch (wybor)
        {
        case 1:
            std::cout << "Podaj slowo: ";
            std::cin >> slowo;
            if (slownik.dodajSlowo(slowo))
            {
                std::cout << "Dodano slowo: " << slowo << std::endl;
            }
            else
            {
                std::cout << "Takie slowo juz istnieje!" << std::endl;
            }
            break;
        case 2:
            std::cout << "Podaj slowo: ";
            std::cin >> slowo;
            if (slownik.usunSlowo(slowo))
            {
                std::cout << "Usunieto slowo: " << slowo << std::endl;
            }
            else
            {
                std::cout << "Brak takiego slowa w slowniku!" << std::endl;
            }
            break;
        case 3:
            std::cout << "Podaj slowo: ";
            std::cin >> slowo;
            if (slownik.wyszukajSlowo(slowo).empty())
            {
                std::cout << "Brak takiego slowa w slowniku!" << std::endl;
            }
            else
            {
                std::cout << "Znaleziono slowo: " << slowo << std::endl;
            }
            break;
        case 4:
            slownik.wypisz();
            break;
        case 5:
            slownik.sortuj();
            break;

        default:
            std::cout << "Dostepne sa tylko opcje 1-5" << std::endl;
            break;
        }
    }
    return 0;
}

void Slownik::napiszMenu()
{
    std::cout << "Menu obslugi slownika:" << std::endl;
    std::cout << "1 - dodaj slowo" << std::endl;
    std::cout << "2 - usun slowo" << std::endl;
    std::cout << "3 - wyszukaj slowo" << std::endl;
    std::cout << "4 - wypisz zawartosc " << std::endl;
    std::cout << "5 - sortuj alfabetycznie" << std::endl;
}

bool Slownik::dodajSlowo(std::string slowo)
{
    std::string wyraz = wyszukajSlowo(slowo);

    if (wyraz.empty())
    {
        slowa.push_back(slowo);
        return true;
    }
    else
    {
        return false;
    }

}

void Slownik::wypisz()
{
    for (std::string slowo : slowa) 
    {
        std::cout << slowo << std::endl;
    }
}

bool Slownik::usunSlowo(std::string slowo)
{
    for (std::vector<std::string>::iterator it = slowa.begin(); it != slowa.end(); ++it)
    {
        if (it->compare(slowo) == 0)
        {
            slowa.erase(it);
            return true;
        }
    }
    return false;
}

std::string Slownik::wyszukajSlowo(std::string slowo)
{
    for (std::vector<std::string>::iterator it = slowa.begin(); it != slowa.end(); ++it)
    {
        if (it->compare(slowo)==0)
        {
            return slowo;
        }
    }
    return "";
}

bool porownaj(std::string a, std::string b)
{
    return a < b;
}

void Slownik::sortuj()
{
    std::sort(slowa.begin(), slowa.end(), Slownik::compareFunction);
}

bool Slownik::compareFunction(std::string a, std::string b)
{
    return a < b;
}


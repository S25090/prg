#include "KsiazkaKontaktow.h"
#include "Kontakt.h"
#include <iostream>

void KsiazkaKontaktow::wypiszMenu()
{
    std::cout << "Co chcesz zrobic?" << std::endl;
    std::cout << "1 - szukaj numeru" << std::endl;
    std::cout << "2 - dodaj numer" << std::endl;
    std::cout << "3 - usun numer" << std::endl;
    std::cout << "4 - polacz z kontaktem" << std::endl;
    std::cout << "5 - wypisz numery" << std::endl;
    std::cout << "0 - wyjdz" << std::endl;

}

void KsiazkaKontaktow::wypiszKontakty()
{
    for (Kontakt kontakt : kontakty)
    {
        kontakt.wypiszKontakt();
        std::cout << std::endl;
    }
}

bool KsiazkaKontaktow::wyszukajKontakt(int numerTelefonu, Kontakt& kontakt)
{
    for (std::vector<Kontakt>::iterator it = kontakty.begin(); it != kontakty.end(); ++it)
    {

        if (it->dajNumerTelefonu() == numerTelefonu)
        {
            kontakt = *it;
            return true;
        }
    }
    return false;
}

void KsiazkaKontaktow::dodajNumer(int numerTelefonu, std::string nazwisko)
{
    Kontakt kontakt;
    if (wyszukajKontakt(numerTelefonu, kontakt))
    {
        std::cout << "Taki numer juz istnieje" << std::endl;
        return;
    }
    kontakt = Kontakt(numerTelefonu, nazwisko, 0);
    kontakty.push_back(kontakt);
}

bool KsiazkaKontaktow::usunKontakt(int numerTelefonu)
{
    for (std::vector<Kontakt>::iterator it = kontakty.begin(); it != kontakty.end(); ++it)
    {
        if (it->dajNumerTelefonu() == numerTelefonu)
        {
            kontakty.erase(it);
            return true;
        }
    }
    return false;
}

bool KsiazkaKontaktow::polacz(std::string nazwisko)
{
    for (std::vector<Kontakt>::iterator it = kontakty.begin(); it != kontakty.end(); ++it)
    {
        if (it->dajNazwisko().compare(nazwisko) == 0)
        {
            it->zwiekszLiczbePolaczen();
            return true;
        }
    }
    return false;
}

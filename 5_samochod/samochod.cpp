
#include <iostream>
#include "Samochod.h"
#include <format>
#include <chrono>
#include <ctime>
#include <iomanip>



auto main() -> int
{
    Samochod samochod1 = Samochod("Mercedes", "S350", 2015, 18000);
    samochod1.ustawCeneWyjsciowa(120000);
    samochod1.obliczCeneKoncowa();
    std::cout << samochod1.toString() << std::endl;
    std::cout << "cena koncowa: " << samochod1.cenaKoncowa << std::endl << std::endl;

    Samochod samochod2 = Samochod("BMW", "F10", 2017, 184);
    samochod2.ustawCeneWyjsciowa(60000);
    samochod2.obliczCeneKoncowa();
    std::cout <<  samochod2.toString() << std::endl;
    std::cout << "cena koncowa: " << samochod2.cenaKoncowa << std::endl << std::endl;

    Samochod samochod3 = Samochod("Volvo", "XC 60", 2020, 10000);
    samochod3.ustawCeneWyjsciowa(220000);
    samochod3.obliczCeneKoncowa();

    std::cout << samochod3.toString() << std::endl;
    std::cout << "cena koncowa: " << samochod3.cenaKoncowa << std::endl << std::endl;

}

std::string Samochod::toString()
{
    std::string opis = "marka: " + marka + " model: " + model + " rokProdukcji: " + std::to_string(rokProdukcji) + " przebieg: " + std::to_string(przebieg);
    return opis;
}

Samochod::Samochod(std::string const marka, std::string const model, unsigned const rokProdukcji, unsigned przebieg) :
    marka{marka},
    model{model},
    rokProdukcji{rokProdukcji},
    przebieg{przebieg},
    cenaWyjsciowa{0},
    cenaKoncowa{0}
{
}

void Samochod::ustawCeneWyjsciowa(unsigned cena)
{
    cenaWyjsciowa = cena;
}

int Samochod::currentDateYear() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y", &tstruct);

    return atoi(buf);
}

void Samochod::obliczCeneKoncowa()
{
    cenaKoncowa = cenaWyjsciowa - (Samochod::currentDateYear() - rokProdukcji) * 10000 - 3 * przebieg;
    if (cenaKoncowa < 0)
    {
        cenaKoncowa = 0;
    }
}
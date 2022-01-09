
#include <iostream>
#include <ctime>
#include "Pacjent.h"
#include "RejestrPacjentow.h"

void obslugaMenuGlowne();

auto main() -> int
{
    obslugaMenuGlowne();
}

void obslugaMenuGlowne()
{
    RejestrPacjentow rejestr;
    int wybor;
    std::string data;

    
    /*Pacjent pacjent1 = Pacjent("jan", "abc", "Jan", "Kowalski");
    Pacjent pacjent2 = Pacjent("ala", "123", "Alicja", "Wosik");

    pacjent1.datySzczepien.push_back("03-12-2021");
    pacjent1.datySzczepien.push_back("04-04-2021");
    pacjent1.datySzczepien.push_back("04-04-2020");

    
    rejestr.rejestruj(pacjent1);
    rejestr.rejestruj(pacjent2);*/
    

    while (true)
    {
        rejestr.wyswietlMenu();
        std::cin >> wybor;

        if (wybor == 1)
        {
            std::string login, haslo;
            std::cout << "Podaj login: " << std::endl;
            std::cin >> login;
            std::cout << "Podaj haslo: " << std::endl;
            std::cin >> haslo;

            rejestr.zaloguj(login, haslo);
        }
        else if (wybor == 2)
        {
            std::string login, haslo, imie, nazwisko;
            std::cout << "Podaj login: " << std::endl;
            std::cin >> login;
            std::cout << "Podaj haslo: " << std::endl;
            std::cin >> haslo;
            std::cout << "Podaj imie: " << std::endl;
            std::cin >> imie;
            std::cout << "Podaj nazwisko: " << std::endl;
            std::cin >> nazwisko;

            Pacjent pacjent = Pacjent(login, haslo, imie, nazwisko);
            rejestr.rejestruj(pacjent);

        }
        else if (wybor == 3)
        {
            break;
        }

    }
}


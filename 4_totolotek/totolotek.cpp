
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

int losujLiczbe();

auto main(int argc, char* argv[]) -> int
{
    // initialize random number generator
    srand(time(0));

    auto liczbyObstawione = std::vector <int>{};

    for (int i = 1; i < argc; i++)
    {
        int liczba = atoi(argv[i]);
        liczbyObstawione.push_back(liczba);
    }

    std::cout << "Obstawione liczby to ";
    for (auto const& liczba : liczbyObstawione) 
    {
        std::cout << liczba << " ";
    }
    std::cout << std::endl;


    std::cout << "Wylosowane liczby to ";
    
    std::vector<int> liczbyTrafione;
    int liczbaWylosowana = 0;

    for (int i = 0; i < argc - 1; i++)
    {
        liczbaWylosowana = losujLiczbe();
        for (int liczba : liczbyObstawione)
        {
            if (liczbaWylosowana == liczba)
            {
                liczbyTrafione.push_back(liczbaWylosowana);
            }
        }

        std::cout << liczbaWylosowana << " ";
    }
    std::cout << std::endl;

    std::cout << "Trafiles " << liczbyTrafione.size() << " z " << argc - 1;
    for (int liczba : liczbyTrafione)
    {

    }
}

int losujLiczbe()
{
    return (rand() % 10) + 1;
}
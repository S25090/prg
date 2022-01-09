
#include <iostream>
#include <vector>
#include <math.h>

int sito(std::vector<int>& tab);
bool czyPierwsza(int liczba, int &liczbaIteracji);

// algorytm zaczerpniety z 
// https://en.wikipedia.org/wiki/Primality_test
// sito erastotenesa zeby znalezc liczby pierwsze do pierwiastka z badanej liczby
// jezeli badana liczba nie jest podzielna przez liczby pierwsze to jest liczba pierwsza

auto main() -> int
{
    int liczba = 17;
    int liczbaIteracji = 0;

    //int liczba = 16127;

    std::cout << "Podaj liczbe: ";
    std::cin >> liczba;

    if (czyPierwsza(liczba, liczbaIteracji))
    {
        std::cout << "To jest liczba pierwsza" << std::endl;
    }
    else
    {
        std::cout << "To nie jest liczba pierwsza" << std::endl;
    }
    std::cout << "liczbaIteracji: " << liczbaIteracji << std::endl;

}

bool czyPierwsza(int liczba, int &liczbaIteracji)
{
    int pierwiastek = (int) sqrt(liczba);

    std::vector<int> tab(pierwiastek + 1);

    liczbaIteracji = sito(tab);

    /*for (int i = 1; i < tab.size(); i++) {
        if (tab[i] == 1) {
            std::cout << i << " ";
        }
    }*/

    int i = 2;
    while (i < tab.size())
    {
        liczbaIteracji++;

        if (tab[i] == 1) 
        {
            if (liczba % i == 0)
            {
                return false;
            }
        }
        i++;
    }
    return true;
}


int sito(std::vector<int> &tab) 
{
    int liczbaIteracji = 0;

    for (int i = 0; i < tab.size(); ++i)
    {
        liczbaIteracji++;
        tab[i] = 1;
    }
    tab[0] = 0;
    tab[1] = 0;

    int i = 2;

    while (i * i <= tab.size())
    {
        if (tab[i] == 0)
        {
            liczbaIteracji++;
            i++;
            continue;
        }
        int j = i * i;
        while (j < tab.size())
        {
            tab[j] = 0;
            j += i;
            liczbaIteracji++;
        }       
        i++;
    }
    return liczbaIteracji;
}

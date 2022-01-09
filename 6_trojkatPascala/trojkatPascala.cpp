#include <iostream>
#include <iomanip>

const int MAX_LICZBA_WIERSZY = 100;

int main()
{
    int liczbaWierszy = 0;

    std::cout << "Wpisz ilosc wierszy : ";

    if(liczbaWierszy > MAX_LICZBA_WIERSZY)
    {
        std::cout << "Liczba wierszy moze wynosic maksymalnie: " << MAX_LICZBA_WIERSZY << std::endl;
    }

    std::cin >> liczbaWierszy;

    int tab[MAX_LICZBA_WIERSZY][MAX_LICZBA_WIERSZY];

    std::cout << std::endl;

    int nrWiersza = 0;

    for (int w = 0; w < liczbaWierszy; w++)
    {
        for (int k = 0; k < nrWiersza+1; k++)
        {
            if (k == 0 || k == nrWiersza)
            {
                tab[w][k] = 1;
            }
            else
            {
                tab[w][k] = tab[w - 1][k - 1] + tab[w - 1][k];
            }
        }
        nrWiersza++;
    }
    
    int liczbaSpacji = 0;
    nrWiersza = 0;
    liczbaSpacji = liczbaWierszy - 1;

    for (int w = 0; w < liczbaWierszy; w++)
    {
        for (int s = 0; s < liczbaSpacji; s++)
        {
            std::cout << "     ";
        }
        for (int k = 0; k < nrWiersza + 1; k++)
        {
            std::cout << std::setw(5) << tab[w][k] << "     ";
        }
        
        liczbaSpacji--;

        std::cout << std::endl;
        nrWiersza++;
    }

    return 0;
}

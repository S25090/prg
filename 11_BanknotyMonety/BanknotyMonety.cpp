
#include <iostream>

void rozkladNominalow(int kwota);

int main()
{
    int kwota;
 
    std::cout << "Podaj kwote w zlotych: ";
    std::cin >> kwota;

    rozkladNominalow(kwota);
}

void rozkladNominalow(int kwota)
{
    int tab[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500 };
    int ileNominalow;

    for (int i = (sizeof(tab) / sizeof(*tab)) - 1; i >= 0; --i)
    {
        ileNominalow = kwota / tab[i];

        if (ileNominalow > 0)
        {
            std::cout << "Liczba nominalow: " << tab[i] << " wynosi: " << ileNominalow << " szt" << std::endl;
        }
        kwota = kwota % tab[i];
    }
}
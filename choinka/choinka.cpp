
#include <iostream>
auto narysujChoinke(int wysokosc) -> void;

auto main() -> int
{
    int wysokosc;

    while (true)
    {
        std::cout << "Podaj wysokosc choinki: ";
        std::cin >> wysokosc;
        if (wysokosc >= 3)
        {
            break;
        }

        std::cout << "Wysokosc nie moze byc mniejsza od 3!" << std::endl;
    }
    narysujChoinke(wysokosc);
       
}

auto narysujChoinke(int wysokosc) -> void
{
    int szerokosc = 2 * wysokosc - 3;
    int ileSpacji = 0;
    int ileGwiazdek = 0;

    for (int i = 0; i < wysokosc; i++)
    {
        if (i >= 1)
        {
            if (i == 1)
            {
                ileSpacji = 1;
            }
            else
            {
                ileSpacji = ileSpacji + 2;
            }
            ileGwiazdek = (szerokosc - ileSpacji) / 2;
        }
        int g = ileGwiazdek;
        int s = ileSpacji;
        for (int j = 0; j < szerokosc; j++)
        {
            if (ileGwiazdek == 0)
            {
                std::cout << "*";
                continue;
            }

            if (g > 0)
            {
                std::cout << "*";
                g--;
            }

            if (g == 0)
            {
                if (s > 0)
                {
                    std::cout << " ";
                }
                s--;
                if (s == 0)
                {
                    g = ileGwiazdek;
                }
            }
        }
        std::cout << std::endl;
    }
}

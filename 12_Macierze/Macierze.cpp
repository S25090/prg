
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

void wariantA(std::string** tab, int size);
void wariantB(std::string** tab, int size);
void wariantC(std::string** tab, int size);
void wariantD(std::string** tab, int size);
void wypiszMacierz(std::string** tab, int size);
std::string formatuj(int liczba);

int main()
{   
    int size=0;

    std::string wariant;
    std::cout << "Podaj wariant macierzy (a,b,c,d): ";
    std::cin >> wariant;
    std::cout << std::endl;
    std::cout << "Podaj wymiar macierzy: ";
    std::cin >> size;
    std::cout << std::endl;

    std::string** tab;
    tab = new std::string* [size];

    for (int i = 0; i < size; ++i) {
        tab[i] = new std::string[size];
    }

    if (wariant == "a")
    {
        wariantA(tab, size);
    }
    if (wariant == "b")
    {
        wariantB(tab, size);
    }
    if (wariant == "c")
    {
        wariantC(tab, size);
    }
    if (wariant == "d")
    {
        wariantD(tab, size);
    }

    wypiszMacierz(tab,size);

    delete[] tab;
 }

void wariantA(std::string** tab, int size)
{
    
    for (int w = 0; w < size; ++w)
    {
        int liczba = w + 1;
        for (int k = 0; k < size; ++k)
        {
            tab[w][k] = formatuj(liczba);
            ++liczba;
        }

        ++liczba;
    }
}

void wariantB(std::string** tab, int size)
{

    for (int w = 0; w < size; ++w)
    {
        int liczba = 0;
        for (int k = 0; k < size; ++k)
        {
            if (k >= size - 1 - w)
            {
                ++liczba;
            }
            tab[w][k] = formatuj(liczba);
        }
    }
}

void wariantC(std::string** tab, int size)
{
    for (int w = 0; w < size; ++w)
    {
        int liczba = w * 2;

        for (int k = 0; k < size; ++k)
        {
            if (w == 0)
            {
                liczba += 2;
            }
            else
            {
                if (k == 0)
                {
                    liczba = 2 + w * 2;
                }
                if (k >= w + 1)
                {
                    liczba += 2;
                    
                }
            }
            tab[w][k] = formatuj(liczba);
        }
        ++liczba;
    }

}

void wariantD(std::string** tab, int size)
{
    for (int w = 0; w < size; ++w)
    {
        int liczba = size - w;
        for (int k = 0; k < size; ++k)
        {
            tab[w][k] = formatuj(liczba);
            
            if (liczba > 0)
            {
                --liczba;
            }
        }
    }
}

void wypiszMacierz(std::string** tab, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (j == 0)
            {
                std::cout << "[";
            }

            std::cout << tab[i][j];

            if (j < size - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
        std::cout << std::endl;
    }
}

std::string formatuj(int liczba)
{
    std::stringstream ss;
    ss << std::setw(3) << liczba;
    return ss.str();
}
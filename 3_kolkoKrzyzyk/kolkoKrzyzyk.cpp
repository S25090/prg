
#include <iostream>
void rysujPlansze();
bool wstawZnak(char znak, int pozycja);
bool czyWygrana(int &nrGracza, char znakGracza1);
int dajNrGracza(char znak, char znakGracza1);
int zmienGracza(int nrGracza);
char dajZnakGracza(int nrGracza, char znakGracza1);
void gra();
char zapytajOZnakGracza1();

char tab[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int main()
{
	rysujPlansze();
	gra();
}

void rysujPlansze()
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << tab[i][0] << "|" << tab[i][1] << "|" << tab[i][2] << std::endl;
		if (i != 2)
		{
			std::cout << "-----" << std::endl;
		}
		else
		{
			std::cout << std::endl << std::endl;
		}	
	}
}
bool wstawZnak(char znak, int pozycja)
{
	int kolumna=0;
	int wiersz=0;

	if (pozycja <= 3)
	{
		wiersz = 0;
		kolumna = pozycja - 1;
	}
	else if (pozycja <= 6)
	{
		wiersz = 1;
		kolumna = pozycja - 4;
	}
	else if (pozycja <= 9)
	{
		wiersz = 2;
		kolumna = pozycja - 7;
	}

	int wartoscLiczbowaPozycji = tab[wiersz][kolumna] - '0';
	if (wartoscLiczbowaPozycji >= 1 && wartoscLiczbowaPozycji <= 9)
	{
		tab[wiersz][kolumna] = znak;
		return true;
	}

	return false;
}

bool czyWygrana(int &nrGracza, char znakGracza1)
{
	char znak;

	for (int i = 0; i < 3; i++)
	{
		if (tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2])
		{
			znak = tab[i][0];
			nrGracza = dajNrGracza(znak, znakGracza1);
			return true;
		}
		if (tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i])
		{
			znak = tab[0][i];
			nrGracza = dajNrGracza(znak, znakGracza1);
			return true;
		}
	}

	if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2])
	{
		znak = tab[0][0];
		nrGracza = dajNrGracza(znak, znakGracza1);
		return true;
	}

	if (tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0])
	{
		znak = tab[0][2];
		nrGracza = dajNrGracza(znak, znakGracza1);
		return true;
	}

	return false;
}

int dajNrGracza(char znak, char znakGracza1)
{
	if (znakGracza1 == znak)
	{
		return 1;
	}
	return 2;
}

char dajZnakGracza(int nrGracza, char znakGracza1)
{
	if (nrGracza == 1)
	{
		return znakGracza1;
	}

	if (znakGracza1 == 'O')
	{
		return 'X';
	}
	else
	{
		return 'O';
	}
}

char zapytajOZnakGracza1() {
	int wybor = 0;
	char znakGracza1;

	while (true)
	{
		std::cout << "Wybierz znak dla gracza 1: " << std::endl;
		std::cout << " 1. O" << std::endl;
		std::cout << " 2. X" << std::endl;
		std::cin >> wybor;
		if (wybor < 1 || wybor>2)
		{
			std::cout << "Wprowadz 1 lub 2!" << std::endl;
			std::cout << std::endl;
			continue;
		}
		break;
	}

	if (wybor == 1)
	{
		znakGracza1 = 'O';
	}
	else
	{
		znakGracza1 = 'X';
	}

	return znakGracza1;
}

void gra()
{
	int nrAktualnegoGracza=1;
	int pozycja;
	int nrZwyciezcy = 0;
	
	char znakGracza1 = zapytajOZnakGracza1();

	for (int i = 0; i < 9; i++)
	{
		while (true)
		{
			std::cout << "Podaj pozycje gracza nr " << nrAktualnegoGracza << ": ";
			std::cin >> pozycja;

			if (pozycja < 0 || pozycja > 9)
			{
				std::cout << "Pozycja musi byc w przedziale 1-9" << std::endl;
				continue;
			}

			if (wstawZnak(dajZnakGracza(nrAktualnegoGracza, znakGracza1), pozycja) == false)
			{
				std::cout << "Ta pozycja jest juz zajeta!" << std::endl;
				continue;
			}
			break;
		}
		
		
		rysujPlansze();
		if (czyWygrana(nrZwyciezcy, znakGracza1))
		{
			std::cout << "Wygral gracz nr: " << nrZwyciezcy << std::endl;
			std::cout << "Gratuluje! :) " << std::endl;
			exit(0);
		} 

		nrAktualnegoGracza = zmienGracza(nrAktualnegoGracza);
		
	}
	std::cout << "Nikt nie wygral, sprobuj ponownie" << std::endl;

}

int zmienGracza(int nrGracza)
{
	if (nrGracza == 1)
	{
		return 2;
	}
	return 1;
}
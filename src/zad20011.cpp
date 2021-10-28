#include <iostream>
#include <string>

using namespace std;


auto main() -> int
{
	int wysokosc, szerokosc;
	cout << "Podaj wysokosc prostokata: " << endl;
	cin >> wysokosc;
	cout << "Podaj szerokosc prostokata: " << endl;	
	cin >> szerokosc;

	for (int w = 0; w < wysokosc; w++)
	{
		for (int s = 0; s < szerokosc; s++)
		{
			cout << '*';
		}

		cout << endl;	
	}


}


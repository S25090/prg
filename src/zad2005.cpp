#include <iostream>
#include <string>
using namespace std;

auto ask_user_for_integer(std::string const prompt) -> int;


auto main() -> int
{
	int liczba, sumaPierwszych;

	liczba = ask_user_for_integer("Wprowadz liczbe: ");
	
	for ( int i=2; i < liczba; i++ )
	{
	    if (  liczba % i == 0 )
	    {
	        cout << "Podana liczba nie jest liczba pierwsza" << endl;
			return 0;
	    }

	}

	cout << "Podana liczba jest liczba pierwsza" << endl;

	sumaPierwszych = liczba;

 	for (int i = liczba - 1; i >= 2; i--)
	{

		// ===========================

		bool czyPierwsza =  true;

		for ( int j=2; j < i; j++ )
		{
			if (  i % j == 0 )
	    	{
				czyPierwsza = false;
				continue;
	 		}

         }
		//============================
	
		if (czyPierwsza == true )
		{

			sumaPierwszych = sumaPierwszych + i;
			
		}
		
	}   
	
	cout << "Suma liczb pierwszych: " << sumaPierwszych << endl;
}


auto ask_user_for_integer(string const prompt) -> int
{
	if (not prompt.empty()) {
	     cout << prompt;
	}
	auto value = string{};
	getline(cin, value);
	return stoi(value);
}


#include <iostream>
#include <string>

auto main () -> int
{

	srand(time(0));
	
	int liczbaLosowa = 1 + rand() % 100;
//	std::cout << "wylosowana liczba: " << liczbaLosowa << std::endl;
	
	int liczba;

	while ( true )
	{
		 std::cout << "guess: ";
	     std::cin >> liczba;

		if ( liczba > liczbaLosowa )
		{
			std::cout << "number too big!" << std::endl;
		}
		if (liczba < liczbaLosowa)
		{
			std::cout << "number too small!" << std::endl;
		}

		if ( liczbaLosowa == liczba )
		{
			std::cout << "just right!" << std::endl;
			break;
		}

	}


	return 0;
}



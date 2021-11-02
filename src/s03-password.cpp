#include <iostream>
#include <string>

auto main (int argc, char* argv[]) -> int
{

	if ( argc != 2 )
	{
		std::cout << "Program wymaga jednego parametru" << std::endl;
		return 0;
	}

	std::string poprawneHaslo = argv[1];

	std::string haslo;
	
	std::cout << "password: ";
	std::cin >> haslo;

	while ( haslo != poprawneHaslo )
	{
		std::cout << "password: ";
		std::cin >> haslo;

	}
	std::cout << "ok!" << std::endl;

	return 0;
}



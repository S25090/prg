#include <iostream>
#include <string>

auto main (int argc, char* argv[]) -> int
{

	if ( argc != 2 )
	{
		std::cout << "Program wymaga jednego parametru" << std::endl;
		return 0;
	}

	int liczbaStartowa = std::stoi(argv[1]);

	for ( int i = liczbaStartowa; i >= 0; i--)
	{
		std::cout << i << "..." << std::endl;
	}

	return 0;
}



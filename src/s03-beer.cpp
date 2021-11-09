#include <iostream>

auto main(int argc, char* argv[]) -> int
{
	
	int liczba = 99;

	if (argc == 2)
	{
		liczba = std::stoi(argv[1]);
	}

    for (int i = liczba; i > 0; --i)
    {
		std::cout << i << " bottles of beer on the wall, ";
        std::cout << i << " bottles of beer. \n";
		std::cout << "Take one down, pass it around, ";
		std::cout << i-1 << " bottles of beer on the wall...\n\n";
    }

    std::cout << "No more bottles of beer on the wall, no more bottles od beer. \n";
	std::cout << "Go to the store and buy some more, " << liczba;
	std::cout << " bottles of beer on the wall..." << std::endl;

    return 0;
}

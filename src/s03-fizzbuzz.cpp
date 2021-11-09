#include <iostream>

auto main (int argc, char* argv[]) -> int
{
	std::cout << "argc: " << argc << std::endl;

    if ( argc != 2)
	{
		std::cout << "Program wymaga podania liczby jako parametru " << std::endl;
		return 0;
	}

	auto const liczba = std::stoi(argv[1]);

    std::cout << "liczba: " << liczba << std::endl;
	
	for ( int n=1; n <= liczba; n++)
	{
	    if ( (n % 3 == 0) && (n % 5 == 0) )
		{
	 		std::cout << n << " FizzBuzz" << std::endl;
		}
		else if ( n % 3 == 0 )
		{
			std::cout << n << " Fizz" << std::endl; // ?
		}
		else if ( n % 5 == 0 )
		{
		    std::cout << n << " Buzz" << std::endl;
		}
		else
		{
			std::cout << n << std::endl;
		}
	}
	return 0;
}



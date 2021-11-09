#include <iostream>
#include <stdio.h>
#include <string.h>

auto czyWystapilParametr (std::string parametr, int argc, char* argv[]) -> bool
{
	for (int i=1; i < argc; ++i)
	{
		if (std::string(argv[i]) == parametr )
			return true; 
	}
	return false;
}

auto main (int argc, char* argv[]) -> int
{
	if ( czyWystapilParametr("-r", argc, argv) )
	{
		for ( int i=argc-1; i > 0; --i)
   		{
			if ( czyWystapilParametr("-l", argc, argv) )
        		std::cout << argv[i] << " " << std::endl;
			else
				std::cout << argv[i] << " ";
   		}
	}
	else
	{
		for ( int i=1; i < argc; ++i) 
		{
			if ( czyWystapilParametr("-l", argc, argv) )
				std::cout << argv[i] << " " << std::endl;
            else
                std::cout << argv[i] << " ";
		}	
	}

	if ( czyWystapilParametr("-n", argc, argv) == false )
   	{
	  std::cout << std::endl;
	}
	
	return 0;
}



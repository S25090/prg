#include <iostream>
#include <string>

auto ask_user_for_integer(std::string const prompt) -> int;


auto main() -> int
{
	int bok = 0;
	
	while ( bok < 3 )
	{
		bok = ask_user_for_integer("Wprowadz wymiary kwadratu: ");
		
		if ( bok < 3 )
		{
			std::cout << "Bok kwadratu musi byc wiekszy od 2 !!!" << std::endl;
		}
	}

	for (int w = 0; w < bok; w++)
	{
		for (int k = 0; k < bok; k++)
		{

			if ( w == 0 || w == bok - 1)
			{
				std::cout << '*';
			}
			else
			{
				if ( k == 0 || k == bok - 1)
				{
					std::cout << '*';
				}
				else
				{
					std::cout << " ";
				}
			}
		}

		std::cout << std::endl;	
	}

}

auto ask_user_for_integer(std::string const prompt) -> int
{
    if (not prompt.empty()) {
        std:: cout << prompt;
    }
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);
}



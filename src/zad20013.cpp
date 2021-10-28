#include <iostream>
#include <string>

auto ask_user_for_integer(std::string const prompt) -> int;


auto main() -> int
{
	int wysokosc, ileKolumn;

	wysokosc = ask_user_for_integer("Wprowadz wysokosc trojkata: ");

	ileKolumn = wysokosc;

	for (int w = 0; w < wysokosc; w++)
	{

		for (int k = 0; k < ileKolumn; k++)
		{
			std::cout << '*';
		}

		ileKolumn -= 1;

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



#include <iostream>
#include <string>

auto ask_user_for_integer(std::string const prompt) -> int;


auto main() -> int
{
	int wysokosc, ileKolumn;

	wysokosc = ask_user_for_integer("Wprowadz wysokosc trojkata: ");

	ileKolumn = 0;

	for (int w = 0; w < wysokosc; w++)
	{
		ileKolumn += 1;

		for (int k = 0; k < ileKolumn; k++)
		{
			std::cout << '*';
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



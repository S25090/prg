#include <iostream>
#include <string>
auto ask_user_for_integer(std::string const prompt) -> int;


auto main() -> int
{
	int liczba;
	liczba = ask_user_for_integer("Wprowadz liczbe: ");
	std::cout << "Wartosc absolutna: " << abs(liczba) << std::endl;
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


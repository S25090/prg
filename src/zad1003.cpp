#include <iostream>
#include <string>
auto ask_user_for_integer(std::string const prompt) -> int;


auto main() -> int
{
	int liczba1,liczba2;
	liczba1= ask_user_for_integer("wprowadz pierwsza liczbe: ");
	liczba2= ask_user_for_integer("wprowadz druga liczbe: ");
	std::cout << "iloczyn liczb: " << liczba1*liczba2 << std::endl;
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


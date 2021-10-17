#include <iostream>
#include <string>
auto ask_user_for_integer(std::string const prompt) -> int;


auto main() -> int
{
	int liczba1,liczba2;

	liczba1 = ask_user_for_integer("Wprowadz pierwsza liczbe: ");
	liczba2 = ask_user_for_integer("Wprowadz druga liczbe: ");
	
	for(int i=liczba1; i<liczba2; i++)
	std::cout << i << std::endl;
	

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


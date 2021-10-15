#include <iostream>
#include <string>
auto ask_user_for_integer(std::string const prompt) -> int;


auto main() -> int
{
	int liczba1,liczba2;

	liczba1= ask_user_for_integer("wprowadz pierwsza liczbe: ");
	liczba2= ask_user_for_integer("wprowadz druga liczbe: ");
	 
	if(liczba1>liczba2)
	{ 
	   std::cout << "liczba wieksza: " << liczba1 << std::endl;
	}  
	else if(liczba2>liczba1)
	{
	   std::cout << "liczba wieksza: " << liczba2 << std::endl;
	}
	else
	{
	   std::cout << "liczby sa rowne" << std::endl;
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


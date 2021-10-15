#include <iostream>
#include <string>
auto ask_user_for_integer(std::string const prompt) -> int;


auto main() -> int
{
	int liczba1,liczba2,liczba3,najwieksza;

	liczba1 = ask_user_for_integer("Wprowadz pierwsza liczbe: ");
	liczba2 = ask_user_for_integer("Wprowadz druga liczbe: ");
	liczba3 = ask_user_for_integer("Wprowadz trzecia liczbe: ");

	if (liczba1 > liczba2)
	{
	  najwieksza = liczba1;
	}
	else
	{
	  najwieksza = liczba2;
	}

        if (liczba3 > najwieksza)
	{
          najwieksza = liczba3;
        }
	std::cout << "Najwieksza z liczb: " << najwieksza << std::endl;
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


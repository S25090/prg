#include <iostream>
#include <string>
auto ask_user_for_integer(std::string const prompt) -> int;


auto main() -> int
{
	int liczba1,liczba2,c;
        liczba1 = ask_user_for_integer("Wprowadz pierwsza liczbe: ");
	liczba2 = ask_user_for_integer("Wprowadz druga liczbe: ");
	c = ask_user_for_integer("Wprowadz trzecia liczbe: ");
	
	while ( c == 0 )
	{
	    std::cout << "Podaj inna liczbe (niezerowa) " << std::endl;
	    c = ask_user_for_integer("Wprowadz trzecia liczbe: ");
	}

        for(int i=liczba1; i<liczba2; i++)
	{
	  {
              if (i % c == 0)
       	         std::cout <<  i  << std::endl;
	  }
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


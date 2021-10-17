#include <iostream>
#include <string>
using namespace std;

auto ask_user_for_integer(std::string const prompt) -> int;


auto main() -> int
{
	int start,koniec,s;

	start = ask_user_for_integer("Wprowadz pierwsza liczbe: ");
	koniec = ask_user_for_integer("Wprowadz druga liczbe: ");
	s = ask_user_for_integer("Wprowadz krok petli: ");
	
	if ( s == 0 )
        {
	    cout << "Krok petli nie moze byc rowny 0!" << endl;
	    return 0;
	}
	
	if ( s > 0 )
	{
	   if ( koniec < start )
	   {
		cout << "Gdy krok jest dodatni to druga liczba musi byc wieksza od pierwszej" << endl;
		return 0;
	   }

           for (int i = start; i < koniec; i = i+s)
               cout << i << endl;

	}   
        else
	{
           if ( koniec > start )
           {
                cout << "Gdy krok jest ujemny to druga liczba nie moze byc wieksza od pierwszej" << endl;
                return 0;
           }

	   for (int i = start; i > koniec; i = i+s)
               cout << i << endl;

        }   

}


auto ask_user_for_integer(string const prompt) -> int
{
	if (not prompt.empty()) {
	     cout << prompt;
	}
	auto value = string{};
	getline(cin, value);
	return stoi(value);
}


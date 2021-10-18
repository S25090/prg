#include <iostream>
#include <string>

using namespace std;

auto ask_user_for_integer(string const prompt) -> int;

auto czyPodzielna(int liczba, int dzielnik) -> bool
{
	if ( liczba % dzielnik == 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

auto main() -> int
{
	int limit = ask_user_for_integer("Wprowadz limit: ");
	int dzielnik = ask_user_for_integer("Wprowadz dzielnik: ");
	int suma = 0;

	for (int i = 1; i <= limit; i++ )
	{
		if (czyPodzielna(i, dzielnik))
		{
			suma = suma + i;
		}
		
	}
	cout << "Suma: " << suma << endl;	
	
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


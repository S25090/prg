#include <iostream>
#include <string>

using namespace std;

auto ask_user_for_integer(string const prompt) -> int;
auto silnia(int const) -> int;

auto main() -> int
{
	int liczba = ask_user_for_integer("Wprowadz liczbe: ");

	cout << "Silnia: " << silnia(liczba) << endl;	
	
}

auto silnia(int const liczba) -> int
{
	int silnia = 1;

	for (auto i = 2; i <= liczba; i++ )
	{
		silnia = i * silnia;		
	}

	return silnia;
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


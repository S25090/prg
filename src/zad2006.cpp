

#include <iostream>
#include <string>

using namespace std;

auto ask_user_for_integer(string const prompt) -> int;


auto main() -> int
{
	int liczba[5];
	
	for (int i = 0; i <= 5; i++ )
	{
		string prompt = " Wprowadz liczbe #" + to_string(i) + ": ";
		liczba[i] = ask_user_for_integer(prompt);	
	}
	
	for (int i = 0; i < 5; i++ )
	{
		if (liczba[0] < liczba[i+1])
		{
			cout << liczba[0] <<  " < " << liczba[i+1]  << endl;
		}
		else if (liczba[0] > liczba[i+1])
		{
          	cout << liczba[0] <<  " > " << liczba[i+1] << endl;
    	}
		else
		{
          	cout << liczba[0] <<  " == " << liczba[i+1] << endl;
    	}
	
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


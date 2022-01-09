#include <vector>

struct Slownik
{
	std::vector<std::string> slowa;

	Slownik() = default;

	void napiszMenu();
	bool dodajSlowo(std::string slowo);
	bool usunSlowo(std::string slowo);
	void wypisz();
	std::string wyszukajSlowo(std::string slowo);
	void sortuj();

	static bool compareFunction(std::string a, std::string b);

};
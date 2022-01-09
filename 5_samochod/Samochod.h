#include <string>

struct Samochod
{
	std::string marka;
	std::string model;
	unsigned rokProdukcji;
	unsigned przebieg;
	unsigned cenaWyjsciowa;
	int cenaKoncowa;

	Samochod(std::string const marka, std::string const model, unsigned const rokProdukcji, unsigned przebieg);

	void ustawCeneWyjsciowa(unsigned cena);
	void obliczCeneKoncowa();

	std::string toString();

private:
	static int currentDateYear();
};


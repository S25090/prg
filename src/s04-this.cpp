#include <iostream>
#include "s25090/MojaStruktura.h"

auto main() -> int
{
	MojaStruktura obj1 = MojaStruktura();
	obj1.metoda();
	std::cout << "Adres obj1 pobrany operatorem &: " << &obj1 << std::endl;
	
	// drugi obiekt ma inny adres
	MojaStruktura obj2 = MojaStruktura();
	obj2.metoda();
	std::cout << "Adres obj2 pobrany operatorem &: " << &obj2 << std::endl;
}

void MojaStruktura::metoda(){
    std::cout << "Adres obiektu: " << this << std::endl;
}



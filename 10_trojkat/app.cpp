#include <iostream>
#include "Trojkat.h"
#include "RodzajTrojkata.h"


int main()
{
	Trojkat t1 = Trojkat(3, 4, 5);
	Trojkat t2 = Trojkat(4, 3, 5);
	Trojkat t3 = Trojkat(5, 4, 3);

	Trojkat t4 = Trojkat(3, 3, 5);
	Trojkat t5 = Trojkat(8, 8, 3);

	Trojkat t6 = Trojkat(1, 2, 5);



	t1.sprawdz();
	t2.sprawdz();
	t3.sprawdz();
	t4.sprawdz();
	t5.sprawdz();
	t6.sprawdz();

}
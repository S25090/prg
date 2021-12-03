#include <iostream>
#include "s25090/Time.h"
#include <iomanip>
#include <sstream> 

auto main() -> int
{
	Time time = Time(23,59,59);
	std::cout << "przed zmiana: " << time.to_string() << std::endl;
	time.next_second();
	std::cout << "plus sekunda: " << time.to_string() << std::endl;

	time = Time(23, 06, 59);
	std::cout << "przed zmiana: " << time.to_string() << std::endl;
	time.next_second();
	std::cout << "plus sekunda: " << time.to_string() << std::endl;

	time = Time(23, 06, 17);
	std::cout << "przed zmiana: " << time.to_string() << std::endl;
	time.next_second();
	std::cout << "plus sekunda: " << time.to_string() << std::endl << std::endl;

	time = Time(23, 59, 17);
	std::cout << "przed zmiana: " << time.to_string() << std::endl;
	time.next_minute();
	std::cout << "plus minuta: " << time.to_string() << std::endl;

	time = Time(23, 12, 17);
	std::cout << "przed zmiana: " << time.to_string() << std::endl;
	time.next_minute();
	std::cout << "plus minuta: " << time.to_string() << std::endl << std::endl;

	time = Time(23, 12, 17);
	std::cout << "przed zmiana: " << time.to_string() << std::endl;
	time.next_hour();
	std::cout << "plus godzina: " << time.to_string() << std::endl;

	time = Time(12, 12, 17);
	std::cout << "przed zmiana: " << time.to_string() << std::endl;
	time.next_hour();
	std::cout << "plus godzina: " << time.to_string() << std::endl;

	return 0;
}


std::string Time::formatuj(int liczba) const
{
	std::stringstream ss;
	ss << std::setfill('0') << std::setw(2) << liczba;
	return ss.str();
}

Time::Time ( int pGodzina, int pMinuta, int pSekunda ) 
	: godzina{ pGodzina }, minuta{ pMinuta }, sekunda{ pSekunda }
{
}

std::string Time::to_string() const
{
	std::string s1(formatuj((godzina)) + ":" + formatuj((minuta)) + ":" + formatuj((sekunda)));
	return s1;

}

void Time::next_hour()
{
	addHour();
}

void Time::next_minute()
{
	addMinute();
}

void Time::next_second()
{
	if (sekunda != 59)
	{
		sekunda++;
	}
	else
	{
		sekunda = 0;
		addMinute();
	}
}

void Time::addHour()
{
	if (godzina == 24)
		godzina = 0;
	else
		godzina++;
}

void Time::addMinute()
{
	if (minuta == 59)
	{
		minuta = 0;
		addHour();
	}
	else
		minuta++;
}

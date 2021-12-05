#include <iostream>
#include "s25090/Time.h"
#include "s25090/Time_of_day.h"
#include <iomanip>
#include <sstream> 

std::string to_string(Time_of_day timeOfDay) {
	switch (timeOfDay)
	{
	case Time_of_day::RANO:
		return "RANO";
	case Time_of_day::DZIEN:
		return "DZIEN";
	case Time_of_day::WIECZOR:
		return "WIECZOR";
	case Time_of_day::NOC:
		return "NOC";
	default:
		return "NIEPOPRAWNA WARTOSC";
	}
}

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

	Time_of_day timeOfDay = Time_of_day::NOC;
	std::cout << "timeOfDay: " << to_string(timeOfDay) << std::endl << std::endl;


	Time time1 = Time(15, 40, 43);
	Time time2 = Time(11, 25, 40);
	std::cout << "time1: " << time1.to_string() << std::endl;
	std::cout << "time2: " << time2.to_string() << std::endl;
	Time time3 = time1 + time2;
	std::cout << "time1 + time2: " << time3.to_string() << std::endl << std::endl;

	time1 = Time(10, 20, 40);
	time2 = Time(11, 21, 41);
	std::cout << "time1: " << time1.to_string() << std::endl;
	std::cout << "time2: " << time2.to_string() << std::endl;
	time3 = time1 - time2;
	std::cout << "time1 - time2: " << time3.to_string() << std::endl << std::endl;

	time1 = Time(10, 20, 41);
	time2 = Time(10, 20, 40);
	std::cout << "time1: " << time1.to_string() << std::endl;
	std::cout << "time2: " << time2.to_string() << std::endl;
	bool wynik = time1 < time2;
	std::cout << "time1 < time2: " << wynik << std::endl << std::endl;

	time1 = Time(10, 20, 41);
	time2 = Time(10, 20, 40);
	std::cout << "time1: " << time1.to_string() << std::endl;
	std::cout << "time2: " << time2.to_string() << std::endl;
	wynik = time1 > time2;
	std::cout << "time1 > time2: " << wynik << std::endl << std::endl;

	time1 = Time(10, 20, 41);
	time2 = Time(10, 20, 40);
	std::cout << "time1: " << time1.to_string() << std::endl;
	std::cout << "time2: " << time2.to_string() << std::endl;
	wynik = time1 == time2;
	std::cout << "time1 == time2: " << wynik << std::endl << std::endl;


	time1 = Time(10, 20, 41);
	time2 = Time(10, 20, 40);
	std::cout << "time1: " << time1.to_string() << std::endl;
	std::cout << "time2: " << time2.to_string() << std::endl;
	wynik = time1 != time2;
	std::cout << "time1 != time2: " << wynik << std::endl << std::endl;
	
	time1 = Time(01, 20, 41);
	std::cout << "time1: " << time1.to_string() << std::endl;
	std::cout << "count_seconds(): " << time1.count_seconds() << std::endl << std::endl;

	time1 = Time(01, 20, 41);
	std::cout << "time1: " << time1.to_string() << std::endl;
	std::cout << "count_minutes(): " << time1.count_minutes() << std::endl << std::endl;

	time1 = Time(21, 45, 15);
	std::cout << "time1: " << time1.to_string() << std::endl;
	time3 = time1.time_to_midnight();
	std::cout << "time_to_midnight(): " << time3.to_string() << std::endl << std::endl;



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

auto Time::operator+ (Time const time) const
-> Time
{ 
	int liczbaSekund = time.sekunda + sekunda;
	int liczbaMinut = time.minuta + minuta;
	int liczbaGodzin = time.godzina + godzina;

	if ( liczbaSekund > 60)
	{
		liczbaSekund = liczbaSekund % 60;
		liczbaMinut++;
	}
	if (liczbaMinut > 60)
	{
		liczbaMinut = liczbaMinut % 60;
		liczbaGodzin++;
	}
	if (liczbaGodzin > 24)
	{
		liczbaGodzin = liczbaGodzin % 24;
	}

	return Time(liczbaGodzin, liczbaMinut, liczbaSekund);
}

auto Time::operator- (Time const time) const
-> Time
{
	int liczbaSekund = sekunda - time.sekunda;
	int liczbaMinut = minuta - time.minuta ;
	int liczbaGodzin = godzina - time.godzina;

	if (liczbaSekund < 0)
	{
		liczbaSekund = 60 + liczbaSekund;
		liczbaMinut--;
	}

	if (liczbaMinut < 0)
	{
		liczbaMinut = 60 + liczbaMinut;
		liczbaGodzin--;
	}

	if (liczbaGodzin < 0)
	{
		liczbaGodzin = 24 + liczbaGodzin;
	}

	return Time(liczbaGodzin, liczbaMinut, liczbaSekund);
}

auto Time::operator< (Time const time) const
-> bool
{
	if (godzina < time.godzina)
	{
		return true;
	}

	if (godzina == time.godzina)
	{
		if (minuta < time.minuta)
		{
			return true;
		}
		
		if ( minuta == time.minuta)
		{
			if (sekunda < time.sekunda)
			{
				return true;
			}
		}
	}

	return false;
}

auto Time::operator> (Time const time) const
	-> bool
{
	if (godzina > time.godzina)
	{
		return true;
	}

	if (godzina == time.godzina)
	{
		if (minuta > time.minuta)
		{
			return true;
		}

		if (minuta == time.minuta)
		{
			if (sekunda > time.sekunda)
			{
				return true;
			}
		}
	}

	return false;
}

auto Time::operator== (Time const time) const
-> bool
{
	if (godzina == time.godzina)
	{
		if (minuta == time.minuta)
		{
			if (sekunda == time.sekunda)
			{
				return true;
			}
		}
	}

	return false;
}

auto Time::operator!= (Time const time) const
-> bool
{
	if (godzina != time.godzina)
	{
		return true;
	}

	if (minuta != time.minuta)
	{
		return true;
	}

	if (sekunda != time.sekunda)
	{
		return true;
	}

	return false;
}

auto Time::count_seconds() const-> uint64_t
{
	return sekunda + 60 * minuta + 3600 * godzina;
}

auto Time::count_minutes() const-> uint64_t
{
	return minuta + 60 * godzina;
}

auto Time::time_to_midnight() const-> Time
{
	Time polnoc = Time(00, 00, 00);
	Time time = Time(godzina, minuta, sekunda);

	return  polnoc - time;
}

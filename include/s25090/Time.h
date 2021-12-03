#ifndef TIME_H 
#define TIME_H

#include <string>

struct Time
{
	int godzina;
	int minuta;
	int sekunda;

	Time(int godzina, int minuta, int sekunda);

	std::string to_string() const;
	void next_hour();
	void next_minute();
	void next_second();
	std::string formatuj(int liczba) const;
	void addHour();
	void addMinute();
};
#endif
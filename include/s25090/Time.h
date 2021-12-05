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
	Time operator+ (Time const time) const;
	Time operator- (Time const time) const;
	bool operator< (Time const time) const;
	bool operator> (Time const time) const;
	bool operator== (Time const time) const;
	bool operator!= (Time const time) const;
	auto count_seconds() const->uint64_t;
	auto count_minutes() const->uint64_t;
	auto time_to_midnight() const->Time;

};
#endif
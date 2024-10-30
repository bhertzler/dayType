// Benjamin Hertzler
// dayType.cpp, class implementation for dayType.h

#include "dayType.h"
#include <iostream>
#include <string>
using namespace std;


void dayType::setDay(string day_name)
{
	string day_prefix = formatDay(day_name);
	string week_prefix;
	for (int i = 0; i < 7; i++)
	{
		week_prefix = formatDay(daysOfWeek[i]);
		if (week_prefix == day_prefix)
		{
			currentDay = i;
			break;
		}
		else
			currentDay = -1;
	}
}

void dayType::printDay() const
{
	if (Invariant())
	{
		string today = daysOfWeek[currentDay];
		cout << "Today is " << today << "." << endl;
	}
	else
	{
		cout << err << "." << endl;
	}

}

string dayType::getDay() const
{
	if (Invariant())
	{
		string today = daysOfWeek[currentDay];
		return today;
	}
	else
		return err;
}

string dayType::nextDay() const
{
	if (Invariant())
	{
		int tomorrow_index = cycleWeek(1);
		string tomorrow = daysOfWeek[tomorrow_index];
		return tomorrow;
	}
	else
		return err;
}

string dayType::previousDay() const
{
	if (Invariant())
	{
		int yesterday_index = cycleWeek(-1);
		string yesterday = daysOfWeek[yesterday_index];
		return yesterday;
	}
	else
		return err;
}

string dayType::addDays(int days) const
{
	if (Invariant())
	{
		int day_index = cycleWeek(days);
		string new_day = daysOfWeek[day_index];
		return new_day;
	}
	else
		return err;
}

// Constructors

dayType::dayType(string day_name)
{
	setDay(day_name);
}

// Private Functions

int dayType::cycleWeek(int cycle_days) const
{
	int cycle_index = currentDay + cycle_days;
	int day_index = ((cycle_index % 7) + 7) % 7;
	return day_index;
}

string dayType::formatDay(string day)
{
	string prefix = day.substr(0, 2);
	string formatted = "";
	for (char ch : prefix)
		formatted += tolower(ch);
	return formatted;
}

// Class Invariant

bool dayType::Invariant() const
{
	if (currentDay <= 6 && currentDay >= 0)
		return true;
	else
		return false;
}
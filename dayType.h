// Benjamin Hertzler
// dayType.h, the specification file for the class dayType

#pragma once

#include <iostream>
#include <string>
using namespace std;

class dayType
{
public:
	void setDay(string day_name);
	// Function to set the day.
	// The day should be a string containing at least the first three letters of one of the days of the week.
	// Postcondition: The function will set the value of current day to -1 if the input is invalid.

	void printDay() const;
	// Function to output the day name corresponding to currentDay to the console.
	// Precondition: The function will output an error message if the value of currentDay is not between 0 and 6.
	// Postcondition: The output is formatted as the sentence "Today is [currentDay]."

	string getDay() const;
	// Function to return the name of currentDay.
	// Precondition: The string returned will be an error message if the value of currentDay is not between 0 and 6.
	// Postcondition: The value returned will be the string in daysOfWeek at index currentDay.

	string nextDay() const;
	// Function to return the name of the following day.
	// Precondition: The string returned will be an error message if the value of currentDay is not between 0 and 6.
	// Postcondition: The value returned will be the name of the week day immediately after currentDay.

	string previousDay() const;
	// Function to return the name of the previous day.
	// Precondition: The string returned will be an error message if the value of currentDay is not between 0 and 6.
	// Postcondition: The value returned will be the name of the week day immediately before currentDay.

	string addDays(int days) const;
	// Function to increment the day by a specified number of days.
	// Precondition: The string returned will be an error message if the value of currentDay is not between 0 and 6.
	// Postcondition: The value returned will be the name of the week day of the input number of days after currentDay.
	
	dayType(string day_name = "");
	// Constructor with optional parameters, initialized to "" by default.
	// The day is set according to the parameter.
	// Postconditon: currentDay = daysOfWeek[day_name].
	//					Invalid values for day_name will set currentDay to -1.
	//					The default parameters will set currentDay to -1.

private:
	int cycleWeek(int) const;				// Internal function to change the index of the day of the week.
	string formatDay(string);				// Internal function to format input parameter.
	bool Invariant() const;					// Invariant function.

	int currentDay;							// Variable to store the position of the day within the week.
	const string err = "Invalid Day Name.";	// Message displayed if the value of currentDay is out of bounds.
	const string daysOfWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };	// Array to store day names.

};


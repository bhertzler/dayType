// Benjamin Hertzler
// test-program.cpp, test program for dayType.h: this program contains the main() function.

#include "dayType.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	dayType sunday("Sunday");
	dayType saturday;
	dayType monday("monday");
	dayType tuesday("tue");
	dayType wednesday("WED");
	dayType unassigned;
	dayType invalid("Christmas");

	saturday.setDay("Saturday");
	monday.printDay();
	string test_1 = tuesday.getDay();
	string test_2 = wednesday.addDays(14);
	string test_3 = unassigned.getDay();
	string test_4 = invalid.getDay();
	string test_5 = sunday.previousDay();
	string test_6 = saturday.nextDay();

	cout << test_1 << ", " << test_2 << ", " << test_3 << endl
		<< test_4 << ", " << test_5 << ", " << test_6 << endl;

}
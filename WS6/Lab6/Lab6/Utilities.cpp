// Workshop 6
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 14/11/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* ins{};
		std::string str;
		char type;

		std::getline(in, str);
		std::stringstream s(str);
		
		s >> type;

		if (!str.empty())
		{

			if (type == 'c' || type == 'C')
			{
				ins = new Car(s);
			}	
			else if (type == 'r' || type == 'R')
			{
				ins = new Racecar(s);
			}
			else
			{
				throw type;
			}
				
		}

		return ins;
	}
}


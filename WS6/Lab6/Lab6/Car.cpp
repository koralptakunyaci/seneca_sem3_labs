// Workshop 6
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 14/11/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Car.h"

namespace sdds
{
	Car::Car()
	{
		developer = {};
		cond = '\0';
		tSpeed = 0.0;
	}
	Car::Car(std::istream& is)
	{

		std::string tag;
		getline(is, tag, ',');


		std::string tempMake;

		std::getline(is, tempMake, ',');
		tempMake.erase(0, tempMake.find_first_not_of(' '));
		tempMake.erase(tempMake.find_last_not_of(' ') + 1);
	
		developer = tempMake;

		std::string tempCond;
		std::getline(is, tempCond, ',');

		tempCond.erase(0, tempCond.find_first_not_of(' '));
		tempCond.erase(tempCond.find_last_not_of(' ') + 1);

		if (tempCond.empty())
		{
			cond = 'n';
		}
		else if (tempCond == "n" || tempCond == "u" || tempCond == "b")
		{
			cond = tempCond[0];
		}
		else
		{
			throw "Invalid record!";
			std::cout << std::endl;
		}

		std::string tempSpeed;
		std::getline(is, tempSpeed, ',');

		tempSpeed.erase(0, tempSpeed.find_first_not_of(' '));
		tempSpeed.erase(tempSpeed.find_last_not_of(' ') + 1);

		if (isNumber(tempSpeed))
		{
			
			tSpeed = std::stod(tempSpeed);
		}
		else
		{
			throw "Invalid record!";
			std::cout << std::endl;
		}

			
			
	}
	Car::~Car()
	{
	}
	std::string Car::condition() const
	{
		std::string tempCondition{};
		switch (cond)
		{
		case 'n':
			tempCondition = "new";
			break;
		case 'u':
			tempCondition = "used";
			break;
		case 'b':
			tempCondition = "broken";
			break;
		}

		return tempCondition;
	}
	double Car::topSpeed() const
	{
		return tSpeed;
	}
	void Car::display(std::ostream& out) const
	{
		out << "| " << std::setw(10) << std::right << developer << " | " << std::setw(6) << std::left << condition() << " | " << std::setw(6) << std::setprecision(2) << std::fixed << topSpeed() << " |";
	}
	bool Car::isNumber(std::string str)
	{
		bool tempReturn = false;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (isdigit(str[i]) == false)
			{
				tempReturn = false;
			}
			else
			{
				tempReturn = true;
			}
		}
		return tempReturn;
	}
}
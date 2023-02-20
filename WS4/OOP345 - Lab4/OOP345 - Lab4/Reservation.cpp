// Workshop 4
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 23/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "Reservation.h"

namespace sdds {
	Reservation::Reservation()
	{
		resId = "";
		resName = "";
		email = "";
		numOfPeople = 0u;
		m_day = 0u;
		hour = 0u;
	}
	Reservation::~Reservation()
	{
		
	}
	void Reservation::update(int day, int time)
	{
		m_day = day;
		hour = time;
	}
	Reservation::Reservation(const std::string& res)
	{
		std::string temp = res;

		temp.erase(0, res.find_first_not_of(' '));
		resId = temp.substr(0, temp.find(':'));
		resId.erase(resId.find_last_not_of(' ') + 1);

		temp.erase(0, (temp.find(':') + 1));
		temp.erase(0, temp.find_first_not_of(' '));
		resName = temp.substr(0, temp.find(','));
		resName.erase(resName.find_last_not_of(' ') + 1);

		temp.erase(0, (temp.find(',') + 1));
		temp.erase(0, temp.find_first_not_of(' '));
		email = temp.substr(0, temp.find(','));
		email.erase(email.find_last_not_of(' ') + 1);

		temp.erase(0, (temp.find(',') + 1));
		temp.erase(0, temp.find_first_not_of(' '));
		std::string tempStr = temp.substr(0, temp.find(','));
		tempStr.erase(tempStr.find_last_not_of(' ') + 1);
		numOfPeople = std::stoi(tempStr);

		temp.erase(0, (temp.find(',') + 1));
		temp.erase(0, temp.find_first_not_of(' '));
		tempStr = temp.substr(0, temp.find(','));
		tempStr.erase(tempStr.find_last_not_of(' ') + 1);
		m_day = std::stoi(tempStr);

		temp.erase(0, (temp.find(',') + 1));
		temp.erase(0, temp.find_first_not_of(' '));
		tempStr = temp.substr(0, temp.find(','));
		tempStr.erase(tempStr.find_last_not_of(' ') + 1);
		hour = std::stoi(tempStr);
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& src)
	{
		std::string foodTime;
		std::string peopleOrPerson;

		if (src.numOfPeople == 1)
			peopleOrPerson = " person.";
		else
		{
			peopleOrPerson = " people.";
		}

		if (src.hour >= 6 && src.hour <= 9)
		{
			foodTime = "Breakfast";
		}
		else if (src.hour >= 11 && src.hour <= 15)
		{
			foodTime = "Lunch";
		}
		else if (src.hour >= 17 && src.hour <= 21)
		{
			foodTime = "Dinner";
		}
		else
			foodTime = "Drinks";

		os << "Reservation " << std::setw(10) << std::right << src.resId << ": " << std::setw(20) << std::right << src.resName << "  " << std::setw(20) << std::left << "<" + src.email + ">" << "    " << foodTime << " on day " << src.m_day << " @ " << src.hour << ":00 for " << src.numOfPeople << peopleOrPerson << std::endl;

		return os;
	}
}
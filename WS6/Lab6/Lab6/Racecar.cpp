// Workshop 6
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 14/11/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include "Racecar.h"

namespace sdds
{
	Racecar::Racecar(std::istream& in) : Car(in)
	{
		std::string temp;
		std::getline(in, temp);
		temp.erase(0, 1);
		m_booster = std::stod(temp);
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		double tSpeed = 0.0;
		tSpeed = Car::topSpeed() + (Car::topSpeed() * m_booster);
		return tSpeed;
	}
}
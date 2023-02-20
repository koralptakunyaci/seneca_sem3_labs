// Workshop 6
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 14/11/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string developer{};
		char cond{};
		double tSpeed = 0.0;
	public:
		Car();
		Car(std::istream& is);
		~Car();
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		bool isNumber(std::string str);

	};
}









#endif // !SDDS_CAR_H

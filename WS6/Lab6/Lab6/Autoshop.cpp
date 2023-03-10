// Workshop 6
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 14/11/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <vector>
#include "Autoshop.h"

namespace sdds
{
	Autoshop::~Autoshop()
	{
		std::vector <sdds::Vehicle*>::iterator i;
		for (i = m_vehicles.begin(); i != m_vehicles.end(); i++)
		{
			delete* i;
		}
	}
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);

		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		for (size_t i =0; i < m_vehicles.size(); ++i)
		{
			m_vehicles[i]->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}
}
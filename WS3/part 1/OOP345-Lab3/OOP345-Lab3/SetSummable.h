// Workshop 3
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 09/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include <iostream>
#include "Set.h"

namespace sdds
{
	template<int N, typename T>
	class SetSummable : public Set<N, T>
	{
	public:
		T accumulate(const std::string& filter) const
		{
			T object(filter);
			for (unsigned int i = 0; i < this->size(); i++)
			{
				// checking if the object is compatible
				if (object.isCompatibleWith(this->get(i)))
				{
					object += this->get(i);
				}
			}
			return object;
		}
	};
}


#endif // !SDDS_SETSUMMABLE_H

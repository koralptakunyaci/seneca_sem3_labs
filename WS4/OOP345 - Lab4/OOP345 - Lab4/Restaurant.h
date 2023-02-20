// Workshop 4
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 23/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SSDS_RESTAURANT_H
#define SSDS_RESTAURANT_H
#include "Reservation.h"

namespace sdds 
{
	class Restaurant
	{
		Reservation* reservation = nullptr;
		size_t numberOfRes = 0u;
	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		~Restaurant();
		size_t size() const;
		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);
		Restaurant(Restaurant&&)noexcept;
		Restaurant& operator=(Restaurant&&)noexcept;

		friend std::ostream& operator<<(std::ostream&, const Restaurant&);
	};
}


#endif //SSDS_RESTAURANT_H
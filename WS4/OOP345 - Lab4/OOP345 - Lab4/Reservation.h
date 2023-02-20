// Workshop 4
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 23/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SSDS_RESERVATION_H
#define SSDS_RESERVATION_H
#include <iostream>
#include <string>

namespace sdds {
	class Reservation {
		 std::string resId;
		 std::string resName;
		 std::string email;
		 size_t numOfPeople;
		 size_t m_day;
		 size_t hour;
	public:
		Reservation();
		~Reservation();
		void update(int day, int time);
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream&, const Reservation&);

	};
}


#endif //SSDS_RESERVATION_H

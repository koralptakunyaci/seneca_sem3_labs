// Workshop 4
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 23/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SSDS_CONFIRMATIONSENDER_H
#define SSDS_CONFIRMATIONSENDER_H
#include "Reservation.h"

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** reservations = nullptr;
		size_t numberOfRes = 0;
	public:
		ConfirmationSender();
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&)noexcept;
		ConfirmationSender& operator=(ConfirmationSender&&)noexcept;

		friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
	};
}


#endif //SSDS_CONFIRMATIONSENDER_H
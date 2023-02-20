// Workshop 4
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 23/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "ConfirmationSender.h"

namespace sdds
{
	ConfirmationSender::ConfirmationSender()
	{
	
	}
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] reservations;
		reservations = nullptr;
		numberOfRes = 0u;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool temp = false;
		for (size_t i = 0u; i < numberOfRes; i++)
		{
			if (this->reservations[i] == &res)
			{
				temp = true;
			}
		}
		if (temp == false)
		{
			const Reservation** obj = new const Reservation*[numberOfRes + 1];
			for (size_t i = 0u; i < numberOfRes; i++)
			{
				obj[i] = reservations[i];
			}
			obj[numberOfRes] = &res;
			numberOfRes++;
			delete[] reservations;
			reservations = obj;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		
		for (size_t i = 0u; i < numberOfRes; i++)
		{
			if (reservations[i] == &res)
			{
				reservations[i] = nullptr;
				/*const Reservation** tempObj = new const Reservation * [numberOfRes - 1];*/
				for (size_t j = i; j < numberOfRes - 1; j++)
				{
					
					reservations[j] = reservations[j + 1];
				}
				/*delete[] reservations;*/
				reservations[numberOfRes - 1] = nullptr;
				numberOfRes--;
				/*reservations = tempObj;*/
				break;
			}
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& other)
	{
		*this = other;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other)
	{
		if (this != &other)
		{
			delete[] reservations;
			reservations = nullptr;
			numberOfRes = 0;

			this->numberOfRes = other.numberOfRes;
			reservations = new const Reservation*[numberOfRes];
			for (size_t i = 0; i < numberOfRes; i++)
			{
				this->reservations[i] = other.reservations[i];
			}
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& other)noexcept
	{
		*this = std::move(other);
		/*reservations = new const Reservation * [other.numberOfRes];
		numberOfRes = other.numberOfRes;
		for (size_t i = 0; i < numberOfRes; i++)
		{
			reservations[i] = other.reservations[i];
		}
		other.reservations = nullptr;
		other.numberOfRes = 0;*/
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other)noexcept
	{
		if (this != &other)
		{
			delete[] reservations;
			reservations = nullptr;
			this->numberOfRes = other.numberOfRes;
			reservations = other.reservations;
			other.reservations = nullptr;
			other.numberOfRes = 0;
		}
			
		
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs)
	{
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (cs.numberOfRes == 0)
		{
			os << "There are no confirmations to send!" << std::endl;
		}
		else
		{
			for (size_t i = 0; i < cs.numberOfRes; i++)
			{
				
					os << *cs.reservations[i];
				
				
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}
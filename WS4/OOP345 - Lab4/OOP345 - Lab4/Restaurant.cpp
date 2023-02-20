// Workshop 4
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 23/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Restaurant.h"

namespace sdds
{
	Restaurant::Restaurant()
	{
		
	}
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		numberOfRes = cnt;
		reservation = new Reservation[numberOfRes];
		for (size_t i = 0; i < numberOfRes; i++)
		{
			reservation[i] = *reservations[i];
		}
	}
	Restaurant::~Restaurant()
	{
		delete[] reservation;
		reservation = nullptr;
		numberOfRes = 0u;

	}
	size_t Restaurant::size() const
	{
		return numberOfRes;
	}
	Restaurant::Restaurant(const Restaurant& other)
	{
		*this = other;
	}
	Restaurant& Restaurant::operator=(const Restaurant& other)
	{
		if (this != &other)
		{
			//deallocate
			delete[] reservation;
			reservation = nullptr;
			numberOfRes = 0u;

			numberOfRes = other.numberOfRes;
			reservation = new Reservation[numberOfRes];
			for (size_t i = 0; i < numberOfRes; i++)
				this->reservation[i] = other.reservation[i];
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& other)noexcept
	{
		*this = std::move(other);
		/*reservation = new Reservation[other.numberOfRes];
		numberOfRes = other.numberOfRes;
		for (size_t i = 0u; i < numberOfRes; i++)
		{
			reservation[i] = other.reservation[i];
		}
		other.reservation = nullptr;
		other.numberOfRes = 0u;*/
	}
	Restaurant& Restaurant::operator=(Restaurant&& other)noexcept
	{
		if (this != &other)
		{
			//deallocate
			delete[] reservation;
			reservation = nullptr;
			numberOfRes = 0u;

			this->numberOfRes = other.numberOfRes;
			reservation = other.reservation;
			other.reservation = nullptr;
			other.numberOfRes = 0u;

		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const Restaurant& res)
	{
		static int cnt = 0;
		++cnt;
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant (" << cnt << ")" << std::endl;
		os << "--------------------------" << std::endl;
		if (res.numberOfRes == 0u)
		{
			os << "This restaurant is empty!" << std::endl;
		}
		else
		{
			for (size_t i = 0u; i < res.numberOfRes; i++)
			{
				os << res.reservation[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;
		
	}

}
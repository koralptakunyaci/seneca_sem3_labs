// Workshop 5
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 28/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <algorithm>
#include <iomanip>
#include "Movie.h"

namespace sdds
{
	sdds::Movie::Movie()
	{
		std::string title{};
		unsigned int m_year = 0;
		std::string desc{};
	}

	const std::string& sdds::Movie::title() const
	{
		return m_title;
	}

	sdds::Movie::Movie(const std::string& strMovie)
	{
		const char* whiteSpaces = " \f\n\r\t\v";
		std::string temp = strMovie;

		m_title = temp.substr(0, temp.find(","));
		m_title.erase(0, m_title.find_first_not_of(whiteSpaces));
		m_title.erase(m_title.find_last_not_of(whiteSpaces));
		temp.erase(0, temp.find(",") + 1);

		std::string tempStr = temp.substr(0, temp.find(","));
		tempStr.erase(0, tempStr.find_first_not_of(whiteSpaces));
		tempStr.erase(tempStr.find_last_not_of(whiteSpaces));
		temp.erase(0, temp.find(",") + 1);
		m_year = std::stoi(tempStr);

		desc = temp.substr(temp.find_first_not_of(whiteSpaces),
			temp.find_last_not_of(whiteSpaces) + 1);

	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
	
			os << std::setw(40) << movie.title() << " | " << std::setw(4) << movie.m_year << " | " << movie.desc << std::endl;
		
		

		return os;
	}
}


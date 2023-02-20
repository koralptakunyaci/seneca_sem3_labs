// Workshop 5
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 28/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "Book.h"

namespace sdds
{
	Book::Book()
	{
		std::string author{};
		std::string m_title{};
		std::string m_country{};
		unsigned int m_year = 0;
		double m_price = 0.0;
		std::string desc{};
	}

	const std::string& Book::title() const
	{
		return m_title;
	}

	const std::string& Book::country() const
	{
		return m_country;
	}

	const size_t& Book::year() const
	{
		return m_year;
	}

	double& Book::price()
	{
		return m_price;
	}
	Book::Book(const std::string& strBook)
	{
		const char* whiteSpaces = " \f\n\r\t\v";
		std::string temp = strBook;
		author = temp.substr(0, temp.find(","));
		author.erase(0, author.find_first_not_of(whiteSpaces));
		author.erase(author.find_last_not_of(whiteSpaces));
		temp.erase(0, temp.find(",") + 1);

		m_title = temp.substr(0, temp.find(","));
		m_title.erase(0, m_title.find_first_not_of(whiteSpaces));
		m_title.erase(m_title.find_last_not_of(whiteSpaces));
		temp.erase(0, temp.find(",") + 1);

		m_country = temp.substr(0, temp.find(","));
		m_country.erase(0, m_country.find_first_not_of(whiteSpaces));
		m_country.erase(m_country.find_last_not_of(whiteSpaces));
		temp.erase(0, temp.find(",") + 1);

		std::string tempStr = temp.substr(0, temp.find(","));
		tempStr.erase(0, tempStr.find_first_not_of(whiteSpaces));
		tempStr.erase(tempStr.find_last_not_of(whiteSpaces));
		temp.erase(0, temp.find(",") + 1);
		m_price = std::stod(tempStr);

		tempStr = temp.substr(0, temp.find(","));
		tempStr.erase(0, tempStr.find_first_not_of(whiteSpaces));
		tempStr.erase(tempStr.find_last_not_of(whiteSpaces));
		temp.erase(0, temp.find(",") + 1);
		m_year = std::stoi(tempStr);

		desc = temp.substr(temp.find_first_not_of(whiteSpaces),
			   temp.find_last_not_of(whiteSpaces) + 1);
	}
	
	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		os	<< std::setw(20) << book.author << " | " << std::setw(22) << book.title() << " | " 
			<< std::setw(5) << book.country() << " | " << std::setw(4) << book.year() << " | " 
			<< std::setw(6) << std::setprecision(2) << std::fixed << book.m_price << " | " 
			<< book.desc << std::endl;

		return os;
	}

}

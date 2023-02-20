// Workshop 5
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 28/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>

namespace sdds
{
	class Book
	{
		std::string author{};
		std::string m_title{};
		std::string m_country{};
		unsigned int m_year = 0;
		double m_price = 0.0;
		std::string desc{};
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(desc);
		}
		
	};

}

#endif // !SDDS_BOOK_H



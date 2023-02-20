// Workshop 5
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 28/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>

namespace sdds
{
	class Movie
	{
		std::string m_title{};
		unsigned int m_year = 0;
		std::string desc{};
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(desc);
			spellChecker(m_title);
		}
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
}

#endif // !SDDS_MOVIE_H

// Workshop 5
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 28/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <fstream>
#include <iomanip>
#include "SpellChecker.h"

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		if (file)
		{
			std::string tempStr{ "" };
			unsigned int index = 0u;
			do
			{
				std::getline(file, tempStr);
				if (file)
				{
					unsigned int temp = tempStr.find(' ');
					m_badWords[index] = tempStr.substr(0, temp);
					tempStr.erase(0, temp);
					tempStr.erase(std::remove(tempStr.begin(), tempStr.end(), ' '), tempStr.end());
					m_goodWords[index] = tempStr;
					index++;
				}
			} while (file);
		}
		else
		{
			throw "Bad file name!";
		}
			
	}
	void SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < 6; i++)
		{
			while (text.find(m_badWords[i]) != std::string::npos)
				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
			replacement[i]++;
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		for (size_t i = 0; i < 6; i++)
		{
			out << std::right << std::setw(15) << m_badWords[i] << ": " <<  replacement[i] << " replacements" << std::endl;
		}
	}

}
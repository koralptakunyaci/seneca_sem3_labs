// Workshop 2
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 02/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H
#include <iostream>
#include <string>

namespace sdds {
	
	//declarationof StringSet class
	class StringSet
	{
		//declaration of instance variables
		size_t numOfStr;
		std::string* name;
	public:
		//declaration of member functions
		StringSet();
		StringSet(const char* fileName);
		~StringSet();
		size_t size()const;
		std::string operator[](size_t)const;
		StringSet(const StringSet& str);
		StringSet& operator=(const StringSet& str);
		StringSet(StringSet&& str)noexcept;
		StringSet& operator=(StringSet&&)noexcept;
	};
}


#endif // !SDDS_STRINGSET_H
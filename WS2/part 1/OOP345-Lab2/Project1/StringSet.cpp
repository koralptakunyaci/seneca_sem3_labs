// Workshop 2
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 02/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "StringSet.h"
#include "TimedEvents.h"

using namespace std;

namespace sdds {
	//definition of no-argument constructor
	StringSet::StringSet()
	{
		name = nullptr;
		numOfStr = 0;
	}
	//definition of 1-argument constructor
	StringSet::StringSet(const char* fileName)
	{
		numOfStr = 0;
		name = nullptr;
		// creating an object for file and opening the file
		ifstream file(fileName);
		string str;
		// checking if file is open
		if (file.is_open())
		{
			// while there are no errors
			while (!file.eof())
			{
				// if extracting the strings from file is possible
				if (getline(file, str, ' '))
				{
					// increment number of strings
					numOfStr++;
				}
			}
		}
		// allocate the string
			name = new string[numOfStr];
			// close the file
			file.close();
			// open the file
			file.open(fileName);
			// checking if file is open
			if (file.is_open())
			{
				// while there are no errors
				while (!file.eof())
				{
					for (size_t i = 0; i < numOfStr; ++i)
					{
						// extracting the strings from files
						getline(file, name[i], ' ');
					}
				}
			}
		
			file.close();
		
	}
	//definition of size function that returns the number of strings in curret object
	size_t StringSet::size()const
	{
		return this->numOfStr;
	}
	// returning strings at the index.
	string StringSet::operator[](size_t index)const
	{
		// declaration of temprorary string
		string str;
		if (index >= 0 && index < numOfStr)
		{
			// if string is empty, displaying a space
			if (name == nullptr)
			{
				str = "";
			}
			// otherwise displaying the string itself
			else
			{
				str = name[index];
			}
		
		}
		else
		{
			str = "";
		}

		return str;
		
	}
	// copy constructor
	StringSet::StringSet(const StringSet& str)
	{
		name = nullptr;
		numOfStr = 0;
		// copy resources
		*this = str;
	}
	// copy assignment operator
	StringSet& StringSet::operator=(const StringSet& str)
	{
		if (this != &str)
		{
			// shallow copy
			numOfStr = str.numOfStr;
			// deallocation of string
			delete[] name;
			// reallocation of string
			name = new string[numOfStr];

			for (size_t i = 0; i < numOfStr; i++)
			{
				name[i] = str.name[i];
			}
		}

		return *this;
	}
	// move constructor
	StringSet::StringSet(StringSet&& str)noexcept
	{
		name = nullptr;
		numOfStr = 0;
		// move resources
		*this = move(str);
	}
	// move assignment operator
	StringSet& StringSet::operator=(StringSet&& str)noexcept
	{
		if (this != &str)
		{
			// shallow copy
			this->numOfStr = str.numOfStr;
			// deallocate the string
			delete[] name;

			//move resources
			this->name = str.name;
			str.name = nullptr;
		}

		return *this;
	}
	// desctructor
	StringSet::~StringSet()
	{
		// deallocate the string
		delete[] name;
	}
}
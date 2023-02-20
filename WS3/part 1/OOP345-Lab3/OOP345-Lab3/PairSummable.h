// Workshop 3
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 09/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include <iostream>
#include "Pair.h"

using namespace std;

namespace sdds
{
	template <typename V, typename K>
	class PairSummable : public Pair<V, K>
	{
		// declaring static private class members
		static V initial;
		static size_t minFieldWidth;
	public:
		// default constructor
		PairSummable()
		{
			
		}
		// two argument constructor
		PairSummable(const K& key, const V& value = initial) : Pair<V, K> (key, value)
		{
			if (key.size() > minFieldWidth)
			{
				minFieldWidth = key.size();
			}
		}
		bool isCompatibleWith(const PairSummable<V, K>& b) const
		{
			// temproary boolean type variable
			bool temp = false;
			// checking if parameter has the same key with current object
			if (b.key() == this->key())
			{
				temp = true;
			}
			return temp;
		}
		// overloaded += operator
		PairSummable<V, K>& operator += (const PairSummable<V, K>& src)
		{
			if (this != &src)
			{
				*this = PairSummable(this->key(), this->value() + src.value());
			}
			return *this;
		}
		void display(std::ostream& os)const override
		{
			os.setf(ios::left);
			os.width(minFieldWidth);
			Pair<V, K>::display(os);
			os.unsetf(ios::left);
		}

	};
		//defining class variables
		template <typename V, typename K>
		size_t PairSummable<V, K>::minFieldWidth = 0;
		template<typename V, typename K>
		V PairSummable<V, K>::initial = {};
		
		// specializing += operator for string types
		template<>
		PairSummable<string, string>& PairSummable<string, string>::operator +=(const PairSummable<string, string>& src)
		{
			if (this->value() != "")
			{
				*this = PairSummable<string, string>(this->key(), this->value() + ", " + src.value());
				/*this->initial = this->value() + ", " + src.value();*/
			}
			else
			{
				*this = PairSummable<string, string>(this->key(), this->value() + src.value());
				/*this->initial = this->value() + src.value();*/
			}
			
			
			return *this;
		}
		

	
}


#endif // !SDDS_PAIRSUMMABLE_H
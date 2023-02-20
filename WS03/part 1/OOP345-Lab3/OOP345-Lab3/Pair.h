// Workshop 3
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 09/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>

namespace sdds
{
	template <typename V, typename K>

	class Pair
	{
		K m_key;
		V m_value;
		
	public:
		// default constructor
		Pair()
		{}
		// two-argument constructor
		Pair(const K& key, const V& value)
		{
			// copying values
			m_key = key;
			m_value = value;

		}
		const V& value() const
		{
			// returning value component
			return m_value;
		}
		const K& key() const
		{
			// returning key component
			return m_key;
		}
		virtual void display(std::ostream& os) const
		{
			os << m_key << " : " << m_value << std::endl;
		}
	};

	template <typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair)
	{
		pair.display(os);
		return os;
	}
}


#endif // !SDDS_PAIR_H

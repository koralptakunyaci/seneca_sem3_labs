// Workshop 3
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 09/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SET_H
#define SDDS_SET_H


namespace sdds {
	template<int N, typename T>
	class Set
	{
		// declaring class variables
		T arr[N];
		size_t elements = 0;

	public:
		size_t size() const
		{
			// returning number of elements
			return elements;
		}
		const T& get(size_t idx) const
		{
			// returning to the element at index idx
			return arr[idx];
		}
		void operator+=(const T& item)
		{
			// if there is capacity for new element
			if (elements < N)
			{
				// copy item into array
				arr[elements] = item;
				elements++;
			}
		}
	};
}


#endif // !SDDS_SET_H

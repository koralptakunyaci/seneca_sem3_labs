// Workshop 5
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 28/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>

namespace sdds
{
	template <typename T>
	class Collection
	{	
		std::string nameColl{};
		T* m_arr{};
		unsigned int arrSize = 0;
		void (*observer)(const Collection<T>&, const T&) = nullptr;
	public:
		Collection()
		{
			std::string nameColl{};
			T* m_arr{};
			unsigned int arrSize = 0;
		}
		Collection(const std::string& name)
		{
			nameColl = name;
		}
		~Collection()
		{
			delete[] m_arr;
			m_arr = nullptr;
		}
		const std::string& name() const
		{
			return nameColl;
		}
		size_t size() const
		{
			return arrSize;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			this->observer = observer;
		}
		Collection<T>& operator+=(const T& item)
		{
			bool temp = false;
			for (size_t i = 0; i < arrSize && !temp; i++)
			{
				if (item.title() == m_arr[i].title())
				{
					temp = true;
				}
			}
			if (!temp)
			{
				T* newArr = new T[arrSize + 1];
				for (size_t i = 0; i < arrSize; i++)
				{
					newArr[i] = m_arr[i];
				}
				newArr[arrSize] = item;
				delete[] m_arr;
				m_arr = nullptr;

				arrSize++;
				m_arr = new T[arrSize];
				for (size_t i = 0; i < arrSize; i++)
				{
					m_arr[i] = newArr[i];
				}
				delete[] newArr;
				newArr = nullptr;

				if (observer)
				{
					observer((*this), item);
				}

			}
			return *this;
		};
		T& operator[](size_t idx) const
		{
			std::string errMsg = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(arrSize) + "] items.";
			if (idx > arrSize)
			{
				throw std::out_of_range(errMsg);
			}
			else
			{
				return m_arr[idx];
			}
		}
		T* operator[](const std::string& title) const
		{
			bool temp = false;
			T* tempArr = nullptr;
			for (size_t i = 0; i < arrSize && !temp; i++)
			{
				if (m_arr[i].title() == title)
				{
					tempArr = &m_arr[i];
					temp = true;
				}
			}
			return tempArr;

		}
		friend std::ostream& operator<<(std::ostream& os, const Collection& obj)
		{
			for (size_t i = 0; i < obj.size(); i++)
			{
				os << obj[i];
			}
			return os;
		}
	};
}

#endif // !SDDS_COLLECTION_H


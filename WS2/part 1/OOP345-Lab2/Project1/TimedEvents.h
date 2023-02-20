// Workshop 2
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 02/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include <iostream>
#include <chrono>
#include <string>


namespace sdds
{
	// declaration and definition of maximum number of event objets
	const int maxNumOfObj = 10;

	// declare TimedEvents class
	class TimedEvents
	{
		// declaration of instance variables
		int numOfRecords;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
		
		//declaration of array of Event structure
		struct Event
		{
			std::string eventName;
			std::string unitsOfTime;
			std::chrono::steady_clock::duration duration;
		}events[maxNumOfObj];

	public:
		// member functions
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* eventName);
		friend std::ostream& operator<<(std::ostream& o, const TimedEvents& t);
	};
}


#endif // !SDDS_TIMEDEVENTS_H


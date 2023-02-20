// Workshop 2
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 02/10/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "TimedEvents.h"

using namespace std;
// definition of functions
namespace sdds {
	// no-argument constructor
	TimedEvents::TimedEvents() {
		numOfRecords = 0;
		events->eventName = {};
		events->unitsOfTime = {};
		events->duration = {};
	}
	// function for starting timer for an event
	void TimedEvents::startClock()
	{
		// defining the start time
		startTime = std::chrono::steady_clock::now();
	}
	// function for stopping timer for an event
	void TimedEvents::stopClock()
	{
		// defining the end time
		endTime = std::chrono::steady_clock::now();
	}
	// adding an event 
	void TimedEvents::addEvent(const char* name)
	{
		
	
		if (numOfRecords < maxNumOfObj && name[0] != '\0')
		{
			//copying the event name
			events[numOfRecords].eventName = name;
			//copying the units of time
			events[numOfRecords].unitsOfTime = "nanoseconds";
			// allocating the duration
			events[numOfRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
			// incrementing number of records
			++numOfRecords;
			
		}
		
	}
	// insertion operator
	ostream& operator<<(ostream& o, const TimedEvents& t)
	{
		o << "--------------------------" << endl;
		o << "Execution Times:" << endl;
		o << "--------------------------" << endl;
		for (auto i = 0; i < t.numOfRecords; ++i)
		{
			o << setw(21) << left << t.events[i].eventName << ' ' << setw(13) << right << t.events[i].duration.count() << ' ' << t.events[i].unitsOfTime << endl;
		}
		o << "--------------------------" << endl;
		return o;
	}
}
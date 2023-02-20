#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "event.h"



using namespace std;

namespace sdds 
{
	Event::Event() 
	{
		seconds = 0;
		desc[0] = '\0';
	}

	void Event::display()
	{
		unsigned int counter = 1;
		int hour = seconds / 3600;
		int min = (seconds / 60) % 60;
		int sec = seconds % 60;
		if (desc)
		{	
			cout << counter << ". "
			<< setfill('0') << setw(2) << hour 
			<< ":" << setfill('0') << setw(2) << min 
			<< ":" << setfill('0') << setw(2) << sec 
			<< " => " << desc << endl;
		}
		else
		{
			cout << setw(2);
			cout << counter << ". " << "| No Event |" << endl;
		}
	}
	void Event::set()
	{
		desc[0] = '\0';
		seconds = 0;
	}


	void Event::set(char* description)
	{
		if (description != nullptr && description[0] != '\0')
		{
			seconds = g_sysClock;
			strcpy(desc, description);
		}
		else
		{
			desc[0] = '\0';
			seconds = 0;
		}
			
		
	}
	


}
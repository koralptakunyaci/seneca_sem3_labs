#ifndef EVENT_H
#define EVENT_H

static unsigned int g_sysClock;

namespace sdds
{
	class Event
	{
		char desc[128]{'\0'};
		unsigned int seconds = 0;
	public:
		Event();
		void display();
		void set();
		void set(char*);
		


	};
}



#endif // !EVENT_H


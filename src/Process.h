#ifndef _PROCESS_H_
#define _PROCESS_H_
#include <string>
#include <ctime>
using std::string;
using std::wstring;

class Process
{
private:
	wstring processName;
	wstring processID;
	bool running;
	time_t launchTime;	// in seconds
	time_t duration;	// in seconds
	
public:
	Process(const wstring & pn, const wstring & pid = L"", const bool r = false, const time_t & lt = 0);
	Process(const Process &);
	~Process(void) {} ;
	const wstring name(void) const
	{ return processName; }
	void processStarted(void);
	void processEnded(void);
	void updateDuration(void);

	bool operator==(const Process & p) const
	{
		if (processName == p.processName && processID == p.processID)
			return true;
		return false;
	}
	bool operator!=(const Process & p) const
	{
		return !operator==(p);
	}
};



#endif
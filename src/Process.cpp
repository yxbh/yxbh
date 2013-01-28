#include "Process.h"


//================================================
// Constructor
//================================================
Process::Process(const wstring & pn, const wstring & pid, const bool r, const time_t & lt)
	: processName(pn), processID(pid), running(r)
{ 
	duration = 0; 
	if (0 == lt)
		launchTime = time(NULL);
	else
		launchTime = lt;
}

//================================================
// Copy constructor
//================================================
Process::Process(const Process & p)
{
	processName = p.processName;
	running = p.running;
	launchTime = p.launchTime;
	duration = p.duration;
}

//================================================
// tag process as running
//================================================
void Process::processStarted(void)
{
	running = true;
}

//================================================
// tag process as stopped running
//================================================
void Process::processEnded(void)
{
	updateDuration();
	running = false;
}

//================================================
// update running duration of running process
//================================================
void Process::updateDuration(void)
{
	duration = time(NULL) - launchTime;
}
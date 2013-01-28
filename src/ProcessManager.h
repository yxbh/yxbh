#ifndef _PROCESSMANAGER_H_
#define _PROCESSMANAGER_H_
#include "IObjManager.h"
#include "Process.h"

class ProcessManager : protected IObjManager<Process>
{
private:
public:
	ProcessManager() {}
	~ProcessManager() {}
	unsigned processCount() const { return container.size(); }
	void add(const Process & p);
	void remove(const Process & p);
};



#endif


#ifndef _IOBJMANAGER_H_
#define _IOBJMANAGER_H_
#include <vector>
using std::vector;

template<class Type>
class IObjManager
{
protected:
	vector<Type> container;
public:
	IObjManager() {}
	virtual ~IObjManager() {}
	unsigned size() const { return container.size(); }
	virtual void add(const Type &);
	//virtual void remove(const Type &) = 0;

};

// implementations
template<class Type>
void IObjManager<Type>::add(const Type & obj)
{
	container.push_back(obj);
}


#endif


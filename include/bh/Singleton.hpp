#pragma once

#include <cassert>
#include <memory>

/**
 * \class Singleton
 * A utility class utilising the Curiously Recurring Template Pattern for implementing classes
 * that exists only as a global singleton object.
*/
template<class T>
class Singleton
{
protected:
    static std::unique_ptr<T> s_upSingletonInstance;

public:
    /**
     * @return raw pointer to the singleton object instance.
	 */
    static T * getSingleton(void)
	{
		assert(s_upSingletonInstance);
		return s_upSingletonInstance.get();
	}

    /**
	 * Set the single instance to \a instance. Ownership is transferred.
	 */
    static void setSingleton(T * instance)
    {
        assert(instance != s_upSingletonInstance.get());
        s_upSingletonInstance.reset(instance);
    }
};

template<class T>
std::unique_ptr<T> Singleton<T>::s_upSingletonInstance = std::move(std::unique_ptr<T>(nullptr));

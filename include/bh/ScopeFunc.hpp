#pragma once

#include "macro.hpp"

#include <utility>

/**
 * \class ScopeFunc
 * A RAII class that takes a single functor object, executing the object's operator()
 * in the ScopeFunc object's destructor when the ScopeFunc object is destroyed.
*/
template<class Functor_T>
class ScopeFunc
{
private:
    Functor_T m_Functor;

public:
    ScopeFunc(Functor_T && p_rrFunctor) : m_Functor(p_rrFunctor) {}
    ~ScopeFunc(void) { m_Functor(); }

};

template<class Functor_T>
ScopeFunc<Functor_T> makeScopeFunc(Functor_T && p_rrFunctor)
{
    return ScopeFunc<Functor_T>(std::forward<Functor_T>(p_rrFunctor));
}

#define MakeScopeFunc(x) auto MAKE_UNIQUE_NAME() = makeScopeFunc(x);
#define BH_MakeScopeFunc(x) MakeScopeFunc(x);

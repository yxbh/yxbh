#pragma once

#include "macro.hpp"

#include <utility>

namespace bh
{

namespace impl
{

template<typename ... T> class ScopeFuncImpl;
template<> class ScopeFuncImpl<> {};
template<typename First_T, typename ... Rest_T>
class ScopeFuncImpl<First_T, Rest_T...>
    : private ScopeFuncImpl<Rest_T...>
{
private:
    using BaseType = ScopeFuncImpl<Rest_T...>;

    First_T m_Functor;

public:
    ScopeFuncImpl(First_T && p_Functor, Rest_T && ... p_Functors)
        : BaseType(std::forward<Rest_T>(p_Functors)...), m_Functor(p_Functor) {}

    ~ScopeFuncImpl(void) { m_Functor(); }
}; // ScopeFuncImpl

} // impl ns

/**
 * \class ScopeFunc
 * A RAII class that takes an arbitrary number of functor objects, executing the objects' operator()
 * in the ScopeFunc object's destructor when the ScopeFunc object is destroyed.
*/
template<typename ... Functor_T>
class ScopeFunc
    : private impl::ScopeFuncImpl<Functor_T...>
{
private:
    using BaseType = impl::ScopeFuncImpl<Functor_T...>;

public:
    ScopeFunc(Functor_T && ... p_Functors)
        : BaseType(std::forward<Functor_T>(p_Functors)...) {}
};


template<typename ... Functor_T>
ScopeFunc<Functor_T...> makeScopeFunc(Functor_T && ... p_rrFunctor)
{
    return ScopeFunc<Functor_T...>(std::forward<Functor_T>(p_rrFunctor) ... );
}

} // BH ns

/**
 * Create a named ScopeFunc object.
 */
#define MakeNamedScopeFunc(...) auto MAKE_UNIQUE_NAME() = bh::makeScopeFunc(__VA_ARGS__);
/**
 * Create a named ScopeFunc object.
 * \see MakeNamedScopeFunc.
 */
#define BH_MakeNamedScopeFunc(...) MakeNamedScopeFunc(__VA_ARGS__);

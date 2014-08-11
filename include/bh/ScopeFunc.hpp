#pragma once

#include "macro.hpp"

#include <utility>

namespace bh
{

namespace detail
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

} // detail ns

/**
 * \class ScopeFunc
 * A RAII class that takes an arbitrary number of functor objects, executing the objects' operator()
 * in the ScopeFunc object's destructor when the ScopeFunc object is destroyed.
*/
template<typename ... Functor_T>
class ScopeFunc
    : private detail::ScopeFuncImpl<Functor_T...>
{
private:
    using BaseType = detail::ScopeFuncImpl<Functor_T...>;

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

#define MakeScopeFunc(...) auto MAKE_UNIQUE_NAME() = makeScopeFunc(__VA_ARGS__);
#define BH_MakeScopeFunc(...) MakeScopeFunc(__VA_ARGS__);

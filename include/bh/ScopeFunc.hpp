#pragma once

#include "macro.hpp"

#include <utility>

namespace bh
{

namespace impl
{

/** @brief ScopeFunc implementation impl. */
template<typename ... T> class ScopeFuncImpl;
/** @brief ScopeFunc implementation impl. */
template<> class ScopeFuncImpl<> {};
/** @brief ScopeFunc implementation impl. */
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
 * @class ScopeFunc
 * @brief A RAII class that takes a single functor object, executing the object's operator()
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

/**
 * Utility function for creating a ScopeFunc object with an arbitrary amount of functors.
 *
 * Sample usuage:
 * @code
 *      auto scope_func = makeScopeFunc([](void){ std::cout << "end of scope" << std::endl; });
 * @endcode
 * @return a ScopeFunc object.
*/
template<typename ... Functor_T>
ScopeFunc<Functor_T...> makeScopeFunc(Functor_T && ... p_rrFunctor)
{
    return ScopeFunc<Functor_T...>(std::forward<Functor_T>(p_rrFunctor) ... );
}

} // bh ns

/**
 * Utility macro function for creating a ScopeFunc object with an arbitrary amount of functors.
 * This function takes care of creating the ScopeFunc object for you so you don't declare one.
 * makeScopeFunc is used internally.
 *
 * Sample usuage:
 * @code
 *      MakeScopeFunc([](void){ std::cout << "end of scope" << std::endl; });
 * @endcode
 * @return a ScopeFunc object.
*/
#define MakeScopeFunc(...) auto MAKE_UNIQUE_NAME() = bh::makeScopeFunc(__VA_ARGS__);
#define BH_MakeScopeFunc(...) auto BH_MAKE_UNIQUE_NAME() = bh::makeScopeFunc(__VA_ARGS__);

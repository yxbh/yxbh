#pragma once

#include <chrono>
#include <type_traits>

/**
 * @class ElapsedTimer
 * @brief
 *  A simple std::chrono based timer for measuring elapsed time.
 *  Use any of the std::chrono duration type to create a new ElapsedTimer.
 */
template<class Duration_T = std::chrono::milliseconds,
         class Test = typename std::enable_if<
             std::is_same<Duration_T, std::chrono::microseconds>::value ||
             std::is_same<Duration_T, std::chrono::milliseconds>::value ||
             std::is_same<Duration_T, std::chrono::seconds>::value
         >::type
     >
class ElapsedTimer
{
public:
    typedef Duration_T                          DurationType;
    typedef std::chrono::high_resolution_clock  ClockType;
    typedef ClockType::time_point               TimePointType;

private:
    DurationType    m_Duration;
    TimePointType   m_BeforeTP, m_AfterTP;

public:
    ElapsedTimer(void)
        : m_Duration(0), m_BeforeTP(ClockType::now()), m_AfterTP(m_BeforeTP) {}

    /** @return the elapsed time as the templated duration type. */
    inline DurationType elapsed(void)
    {
        m_AfterTP = ClockType::now();
        m_Duration += std::chrono::duration_cast<DurationType>(m_AfterTP - m_BeforeTP);
        m_BeforeTP = m_AfterTP;
        return m_Duration;
    }

    inline void restart(void)
    {
        m_BeforeTP = ClockType::now();
        m_Duration = DurationType(0);
    }
};
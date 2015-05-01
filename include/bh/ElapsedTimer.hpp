/*
Copyright (c) 2015,  Benjamin YanXiang Huang
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of yxbh nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once

#include <chrono>
#include <type_traits>

namespace bh
{

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
}; // ElapsedTimer class

} // bh namespace
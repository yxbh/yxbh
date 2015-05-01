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

#include "ScopeFunc.hpp"

#include <iostream>

/**
 * A macro which prints the current function name twice:
 *  once at the line the macro is used,
 *  the other at the end of the current scope.
 *
 * Place this macro at the beginning of a function's scope for proper scope enter and exit reporting.
 * Works only when FUNCTION_SCOPE_MSG or BH_FUNCTION_SCOPE_MSG is defined.
*/
#if defined(FUNCTION_SCOPE_MSG) or defined(BH_FUNCTION_SCOPE_MSG)
#define DBG_MSG_FUNC_SCOPE \
    const auto FUNC_NAME = __func__; \
    std::clog << "enter: " << FUNC_NAME << std::endl; \
    MakeScopeFunc([&FUNC_NAME](){ std::clog << "exit:  " << FUNC_NAME << std::endl; });
#define BH_DBG_MSG_FUNC_SCOPE \
    const auto FUNC_NAME = __func__; \
    std::clog << "enter: " << FUNC_NAME << std::endl; \
    MakeScopeFunc([&FUNC_NAME](){ std::clog << "exit:  " << FUNC_NAME << std::endl; });
#else
#define DBG_MSG_FUNC_SCOPE
#define BH_DBG_MSG_FUNC_SCOPE
#endif

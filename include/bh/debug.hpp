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

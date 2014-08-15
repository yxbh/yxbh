#include "bh/ScopeFunc.hpp"

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(LibBH_test_ScopeFunc)

BOOST_AUTO_TEST_CASE(test_construction)
{
    MakeNamedScopeFunc([](){ return 0; })
    auto scope_func = bh::makeScopeFunc([](){ return 0; });
}

BOOST_AUTO_TEST_SUITE_END()

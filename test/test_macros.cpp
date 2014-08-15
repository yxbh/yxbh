#include "bh/macro.hpp"

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(LibBH_test_macros)

BOOST_AUTO_TEST_CASE(test_unique_name_gen)
{
    // test unique variable names are created.
    int BH_MAKE_UNIQUE_NAME();
    int BH_MAKE_UNIQUE_NAME();
    int BH_MAKE_UNIQUE_NAME_WITH(abc);
    int BH_MAKE_UNIQUE_NAME_WITH(abc);
}

BOOST_AUTO_TEST_CASE(test_unused_reference)
{
    int var;
    BH_UNUSED(var);
}

BOOST_AUTO_TEST_SUITE_END()

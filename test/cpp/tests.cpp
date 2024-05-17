#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "add.h"
TEST_CASE("Add", "1, 2")
{
    int *c;
    int* d;
    add_CPU(1, 2, c);
    add_GPU(1, 2, d);
    REQUIRE(3 == *c);
    REQUIRE(3 == *d);
}
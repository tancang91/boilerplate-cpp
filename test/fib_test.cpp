#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "fib.h"

TEST_CASE("Fib Test", "[fib]") {
    REQUIRE(fib(0) == 0);
    REQUIRE(fib(1) == 1);
}

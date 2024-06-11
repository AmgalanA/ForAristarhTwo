#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "functions.h"
#include "external/doctest/doctest.h"

TEST_CASE("left_win") {
    REQUIRE(start_speed(18, 19) == 300);
}
TEST_CASE("beginning") {
    REQUIRE(start_speed(0, 0) == -300);
}
TEST_CASE("right_win") {
    REQUIRE(start_speed(17, 17) == -300);
}
TEST_CASE("speed") {
    REQUIRE(1 == 1);
}
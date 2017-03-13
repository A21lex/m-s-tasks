#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <stdio.h>
#include "StrShift.h"

using namespace std;

TEST_CASE("testing StrShift assignment"){
    StrShift me;
    me = "Microsoft";
    CHECK(me.str=="Microsoft");
}

StrShift compareMe("Microsoft");
StrShift compareMeToo("Microsoft");
StrShift compareMeThree("Softomicr");
bool areTheSame = (compareMe == compareMeToo);
bool areTheSameTwo = (compareMe == compareMeThree);
TEST_CASE("testing StrShift comparison"){
    CHECK(areTheSame == true);
    CHECK(areTheSameTwo == false);
}


StrShift example("Microsoft");
std::string example1 = example << 2;
std::string example2 = example << 2;
std::string example3 = example << 7;

TEST_CASE("testing shifting strings to the left") {
    CHECK( example1 =="ftMicroso");
    CHECK( example2 == "softMicro");
    CHECK( example3 == "ftMicroso");
}
StrShift examplez("Microsoft");
std::string examplez1 = examplez >> 2;
std::string examplez2 = examplez >> 2;
std::string examplez3 = examplez >> 7;
TEST_CASE("testing shifting strings to the right") {
    CHECK( examplez1 =="crosoftMi");
    CHECK( examplez2 == "osoftMicr");
    CHECK( examplez3 == "crosoftMi");
}
StrShift negativeExample("Microsoft");
std::string exampleNegative = negativeExample << -2;  //Same as >>7 (since length of "Microsoft" is 9)
std::string exampleNegative2 = negativeExample >> -2; //Same as <<7
std::string exampleZero = negativeExample << 0;
TEST_CASE("testing negative shift values and zero"){
    CHECK (exampleNegative == "crosoftMi");
    CHECK (exampleNegative2 == "Microsoft");
    CHECK (exampleZero == "Microsoft");
}

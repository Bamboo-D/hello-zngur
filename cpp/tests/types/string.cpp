#include "types/string.hpp"

#include <cassert>

using namespace rust::crate::types;

void testRefStr()
{
    auto str_rust = "able was i ere i saw elba"_rs;
    auto str_cpp = intoCpp<std::string_view>(str_rust);
    assert(str_cpp == "able was i ere i saw elba");

    auto string_reversed_rust = reverse_str(str_rust);
    auto string_reversed_cpp = intoCpp<std::string>(string_reversed_rust);
    assert(string_reversed_cpp == "able was i ere i saw elba");
}

void testString()
{
    auto string1_rust = sample_string();
    auto string1_cpp = intoCpp<std::string>(std::move(string1_rust));
    assert(string1_cpp == "Hi, Z!");

    std::string string2_cpp = "Hello, Z!";
    auto string2_rust = intoRust<rust::std::string::String>(string2_cpp);
    auto string2_echoed_rust = echo_string(std::move(string2_rust));
    auto string2_echoed_cpp = intoCpp<std::string>(std::move(string2_echoed_rust));
    assert(string2_echoed_cpp == "Hello, Z!");

    auto string3_rust = "123ABC 一二三"_rs.to_owned();
    reverse_string(string3_rust);
    auto string3_cpp = intoCpp<std::string>(std::move(string3_rust));
    assert(string3_cpp == "三二一 CBA321");
}

int main()
{
    testRefStr();
    testString();

    return 0;
}
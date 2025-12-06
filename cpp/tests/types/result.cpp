#include "types/result.hpp"

#include <cassert>

using namespace rust::crate::types;

void testResultOk()
{
    auto result_rust = is_positive_result(42);
    auto result_cpp = intoCpp<std::expected<std::string, int32_t>>(std::move(result_rust));
    assert(result_cpp.has_value());
    assert(result_cpp.value() == "42 > 0");
}

void testResultErr()
{
    auto result_rust = is_positive_result(0);
    auto result_cpp = intoCpp<std::expected<std::string, int32_t>>(std::move(result_rust));
    assert(!result_cpp.has_value());
    assert(result_cpp.error() == -1);
}

int main()
{
    testResultOk();
    testResultErr();

    return 0;
}
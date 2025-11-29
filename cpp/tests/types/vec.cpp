#include "types/vec.hpp"

#include <cassert>

using namespace rust::crate::types;

template <typename T>
using Vec = rust::std::vec::Vec<T>;

int main()
{
    auto vec1_rust = sample_vec();
    auto vec1_cpp = intoCpp<std::vector<int32_t>>(std::move(vec1_rust));
    assert((vec1_cpp == std::vector<int32_t>{1, 2, 3, 4, 5}));

    std::vector<int32_t> vec2_cpp{10, 20, 30, 40, 50};
    auto vec2_rust = intoRust<Vec<int32_t>>(vec2_cpp);
    auto vec2_echoed_rust = echo_vec(std::move(vec2_rust));
    auto vec2_echoed_cpp = intoCpp<std::vector<int32_t>>(std::move(vec2_echoed_rust));
    assert(vec2_echoed_cpp == vec2_cpp);

    auto vec3_rust = intoRust<Vec<int32_t>>(std::vector<int32_t>{6, 7, 8, 9});
    reverse_vec(vec3_rust);
    auto vec3_cpp = intoCpp<std::vector<int32_t>>(std::move(vec3_rust));
    assert((vec3_cpp == std::vector<int32_t>{9, 8, 7, 6}));
}

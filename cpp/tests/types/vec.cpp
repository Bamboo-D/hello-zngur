#include "types/vec.hpp"

#include <cassert>

using namespace rust::crate::types;

template <typename T>
using Vec = rust::std::vec::Vec<T>;

void testVec()
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

void testVecVec()
{
    auto vecvec1_rust = sample_2d_vec();
    auto vecvec1_cpp = intoCpp<std::vector<std::vector<float>>>(std::move(vecvec1_rust));
    assert((vecvec1_cpp == std::vector<std::vector<float>>{{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}}));

    std::vector<std::vector<float>> vecvec2_cpp{{1.5, 2.5}, {3.5, 4.5}};
    auto vecvec2_rust = intoRust<Vec<Vec<float>>>(vecvec2_cpp);
    auto vecvec2_echoed_rust = echo_2d_vec(std::move(vecvec2_rust));
    auto vecvec2_echoed_cpp = intoCpp<std::vector<std::vector<float>>>(std::move(vecvec2_echoed_rust));
    assert(vecvec2_echoed_cpp == vecvec2_cpp);

    auto vecvec3_rust = intoRust<Vec<Vec<float>>>(std::vector<std::vector<float>>{{2.0, 3.0}, {4.0, 5.0}});
    square_2d_vec(vecvec3_rust);
    auto vecvec3_cpp = intoCpp<std::vector<std::vector<float>>>(std::move(vecvec3_rust));
    assert((vecvec3_cpp == std::vector<std::vector<float>>{{4.0, 9.0}, {16.0, 25.0}}));
}

int main()
{
    testVec();
    testVecVec();

    return 0;
}

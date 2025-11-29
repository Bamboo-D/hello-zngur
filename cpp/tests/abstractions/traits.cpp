#include "types/tuple.hpp"

#include <cassert>

using namespace rust::crate::abstractions;

int main()
{
    auto tuple_rust = sample_tuple();
    auto tuple_cpp = intoCpp<std::pair<size_t, float>>(std::move(tuple_rust));
    assert(tuple_rust.index() == 0);
    assert(tuple_rust.score() == 0.88f);
    assert((tuple_cpp == std::make_pair<size_t, float>(0, 0.88f)));
}

#pragma once

#include "zgenerated.h"

#include "types/conversion_core.hpp"

/* intoCpp */

// rust::Tuple<size_t, float> -> std::pair<size_t, float>
template <>
struct IntoCppTraits<std::pair<size_t, float>, rust::Tuple<size_t, float>>
{
    static std::pair<size_t, float> convert(rust::Tuple<size_t, float> &&rust_tuple) noexcept
    {
        return {rust_tuple.index(), rust_tuple.score()};
    }
};
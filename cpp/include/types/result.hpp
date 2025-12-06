#pragma once

#include "zgenerated.h"

#include "types/conversion_core.hpp"

#include <expected>
#include "types/string.hpp"

/* intoCpp */

// Result<String, i32> -> std::expected<std::string, int32_t>
template <>
struct IntoCppTraits<std::expected<std::string, int32_t>, rust::std::result::Result<rust::std::string::String, int32_t>>
{
    static std::expected<std::string, int32_t> convert(rust::std::result::Result<rust::std::string::String, int32_t> &&rust_result) noexcept
    {
        if (rust_result.is_ok())
        {
            auto rust_string = rust_result.unwrap();
            auto cpp_string = intoCpp<std::string>(rust_string);
            return cpp_string;
        }
        else
        {
            auto err_code = rust_result.unwrap_err();
            return std::unexpected(err_code);
        }
    }
};
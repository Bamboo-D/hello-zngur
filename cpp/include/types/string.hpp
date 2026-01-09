#pragma once

#include "zgenerated.h"

#include "types/conversion_core.hpp"

/* intoCpp */

// &str -> std::string_view
template <>
struct IntoCppTraits<std::string_view, rust::Ref<rust::Str>>
{
    static std::string_view convert(const rust::Ref<rust::Str> &rust_str) noexcept
    {
        auto str_ptr = rust_str.as_ptr();
        auto str_len = rust_str.len();
        return std::string_view((char *)str_ptr, str_len);
    }
};

// String -> std::string
template <>
struct IntoCppTraits<std::string, rust::std::string::String>
{
    static std::string convert(const rust::std::string::String &rust_string) noexcept
    {
        auto rust_str = rust_string.as_str();
        auto cpp_sv = intoCpp<std::string_view>(rust_str);
        return std::string(cpp_sv); // Deep copy
    }
};

/* intoRust */

// std::string_view -> &str
template <>
struct IntoRustTraits<rust::Ref<rust::Str>, std::string_view>
{
    static rust::Ref<rust::Str> convert(const std::string_view cpp_sv) noexcept // string_view is lightweight and designed for cheap copying
    {
        return operator""_rs(cpp_sv.data(), cpp_sv.size());
    }
};

// std::string -> String
template <>
struct IntoRustTraits<rust::std::string::String, std::string>
{
    static rust::std::string::String convert(const std::string &cpp_string) noexcept
    {
        auto rust_str = operator""_rs(cpp_string.data(), cpp_string.size());
        return rust_str.to_owned(); // Deep copy
    }
};

#pragma once

#include "zgenerated.h"

#include "types/conversion_core.hpp"

/* intoCpp */

// Vec<int32_t> -> std::vector<int32_t>
template <>
struct IntoCppTraits<std::vector<int32_t>, rust::std::vec::Vec<int32_t>>
{
    static std::vector<int32_t> convert(rust::std::vec::Vec<int32_t> &&rust_vec) noexcept
    {
        std::vector<int32_t> cpp_vec;

        auto iter = rust_vec.into_iter();
        while (true)
        {
            auto opt = iter.next();
            if (opt.is_none())
                break;
            cpp_vec.push_back(opt.unwrap());
        }

        return cpp_vec;
    }
};

/* intoRust */

// std::vector<int32_t> -> Vec<int32_t>
template <>
struct IntoRustTraits<rust::std::vec::Vec<int32_t>, std::vector<int32_t>>
{
    static rust::std::vec::Vec<int32_t> convert(const std::vector<int32_t> &cpp_vec) noexcept
    {
        auto rust_vec = rust::std::vec::Vec<int32_t>::new_();
        for (const auto &x : cpp_vec)
        {
            rust_vec.push(x);
        }
        return rust_vec;
    }

    static rust::std::vec::Vec<int32_t> convert(std::vector<int32_t> &&cpp_vec) noexcept
    {
        auto rust_vec = rust::std::vec::Vec<int32_t>::new_();
        for (auto &x : cpp_vec)
        {
            rust_vec.push(std::move(x));
        }
        return rust_vec;
    }
};

// std::vector<float> -> Vec<float>
template <>
struct IntoRustTraits<rust::std::vec::Vec<float>, std::vector<float>>
{
    static rust::std::vec::Vec<float> convert(const std::vector<float> &cpp_vec) noexcept
    {
        auto rust_vec = rust::std::vec::Vec<float>::with_capacity(cpp_vec.size());
        for (const auto &f : cpp_vec)
        {
            rust_vec.push(f);
        }
        return rust_vec;
    }

    static rust::std::vec::Vec<float> convert(std::vector<float> &&cpp_vec) noexcept
    {
        auto rust_vec = rust::std::vec::Vec<float>::with_capacity(cpp_vec.size());
        for (auto &f : cpp_vec)
        {
            rust_vec.push(std::move(f));
        }
        return rust_vec;
    }
};

// std::vector<std::vector<float>> -> Vec<Vec<float>>
template <>
struct IntoRustTraits<rust::std::vec::Vec<rust::std::vec::Vec<float>>, std::vector<std::vector<float>>>
{
    template <typename T>
    using Vec = rust::std::vec::Vec<T>;

    static Vec<Vec<float>> convert(const std::vector<std::vector<float>> &cpp_2d_vec) noexcept
    {
        auto rust_2d_vec = Vec<Vec<float>>::with_capacity(cpp_2d_vec.size());
        for (const auto &vec : cpp_2d_vec)
        {
            rust_2d_vec.push(std::move(intoRust<Vec<float>>(vec)));
        }
        return rust_2d_vec;
    }

    static Vec<Vec<float>> convert(std::vector<std::vector<float>> &&cpp_2d_vec) noexcept
    {
        auto rust_2d_vec = Vec<Vec<float>>::with_capacity(cpp_2d_vec.size());
        for (auto &vec : cpp_2d_vec)
        {
            rust_2d_vec.push(std::move(intoRust<Vec<float>>(std::move(vec))));
        }
        return rust_2d_vec;
    }
};
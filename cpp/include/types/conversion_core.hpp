#pragma once

#include <type_traits>
#include <utility>

/* intoCpp */

// 转换特征主模板
template <typename ToCpp, typename FromRust>
struct IntoCppTraits
{
    static_assert(sizeof(ToCpp) == 0, "IntoCppTraits is not specialized for the given pair!"); // 模板实例化时检查，当 ToCpp 类型没有对应的特化转换函数时报错
};

// 统一的 intoCpp 函数
template <typename ToCpp, typename FromRust>
ToCpp intoCpp(FromRust &&from) noexcept(noexcept(IntoCppTraits<ToCpp, std::remove_reference_t<FromRust>>::convert(std::forward<FromRust>(from)))) // 条件性 noexcept 规范，自动根据底层 convert 函数是否为 noexcept 来标记 intoCpp
{
    return static_cast<ToCpp>(IntoCppTraits<ToCpp, std::remove_reference_t<FromRust>>::convert(std::forward<FromRust>(from)));
}

/* intoRust */

template <typename ToRust, typename FromCpp>
struct IntoRustTraits
{
    static_assert(sizeof(ToRust) == 0, "IntoRustTraits is not specialized for the given pair!");
};

template <typename ToRust, typename FromCpp>
ToRust intoRust(FromCpp &&from) noexcept(noexcept(IntoRustTraits<ToRust, std::remove_reference_t<FromCpp>>::convert(std::forward<FromCpp>(from))))
{
    return static_cast<ToRust>(IntoRustTraits<ToRust, std::remove_reference_t<FromCpp>>::convert(std::forward<FromCpp>(from)));
}

// 通用：将 const FromCpp 转发到非 const FromCpp 的特化，避免为 const 版本单独重复实现
template <typename ToRust, typename FromCpp>
struct IntoRustTraits<ToRust, const FromCpp>
{
    static ToRust convert(const FromCpp &from) noexcept(noexcept(IntoRustTraits<ToRust, FromCpp>::convert(std::declval<const FromCpp &>())))
    {
        return IntoRustTraits<ToRust, FromCpp>::convert(from);
    }
};
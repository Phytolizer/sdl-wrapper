#pragma once

#include "pch.h"

template <typename E> struct EnableBitmaskOperations
{
    static constexpr bool enable = false;
};

template <typename E>
requires(EnableBitmaskOperations<E>::enable) constexpr E operator|(E lhs, E rhs)
{
    using underlying_type = typename std::underlying_type<E>::type;
    return static_cast<E>(static_cast<underlying_type>(lhs) |
                          static_cast<underlying_type>(rhs));
}
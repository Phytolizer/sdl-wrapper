#pragma once

#include "pch.h"

namespace sdl::Image
{

enum class InitFlag
{
    none = 0,
    jpg = 1,
    png = 2,
    tif = 4,
    webp = 8,
};

} // namespace sdl::Image

template <> struct EnableBitmaskOperations<sdl::Image::InitFlag>
{
    static constexpr bool enable = true;
};

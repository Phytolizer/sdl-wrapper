#pragma once

#include "pch.h"

namespace sdl
{
enum class BlendMode
{
    none,
    blend,
    add,
    mod,
    mul,
    invalid,
};

BlendMode BlendModeFromSdl(SDL_BlendMode mode);
} // namespace sdl

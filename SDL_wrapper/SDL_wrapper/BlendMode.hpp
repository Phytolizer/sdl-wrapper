#pragma once

#include "pch.h"

namespace sdl
{
enum class BlendMode
{
    none = SDL_BLENDMODE_NONE,
    blend = SDL_BLENDMODE_BLEND,
    add = SDL_BLENDMODE_ADD,
    mod = SDL_BLENDMODE_MOD,
    mul = SDL_BLENDMODE_MUL,
    invalid = SDL_BLENDMODE_INVALID,
};

} // namespace sdl

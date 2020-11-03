#pragma once

#include "Surface.hpp"

#include "pch.h"

namespace sdl
{

class RefSurface final : public Surface
{
    SDL_Surface *m_handle;

  public:
    explicit RefSurface(SDL_Surface *handle);
    struct SDL_Surface *Get() const noexcept override;
};

} // namespace sdl
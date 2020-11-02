#pragma once

#include "Surface.hpp"
#include "pch.h"

namespace sdl
{

class OwnedSurface final : public Surface
{
    SDL_Surface *m_handle;

  public:
    OwnedSurface(SDL_Surface *handle);

    ~OwnedSurface();
    OwnedSurface(const OwnedSurface &) = delete;
    OwnedSurface(OwnedSurface &&other) noexcept;
    OwnedSurface &operator=(const OwnedSurface &) = delete;
    OwnedSurface &operator=(OwnedSurface &&other) noexcept;

    SDL_Surface *Get() const noexcept override;
};

} // namespace sdl
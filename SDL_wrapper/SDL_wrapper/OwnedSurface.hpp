#pragma once

#include "Surface.hpp"
#include "pch.h"

namespace sdl
{

class OwnedSurface final : public Surface
{
    explicit OwnedSurface(SDL_Surface *handle);

    friend class Surface;

  public:
    ~OwnedSurface() override;
    OwnedSurface(const OwnedSurface &) = delete;
    OwnedSurface(OwnedSurface &&other) noexcept;
    OwnedSurface &operator=(const OwnedSurface &) = delete;
    OwnedSurface &operator=(OwnedSurface &&other) noexcept;
};

} // namespace sdl
#pragma once

#include "Surface.hpp"
#include "pch.h"

namespace sdl
{

class OwnedSurface final : public Surface
{
    std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> m_handle;

  public:
    explicit OwnedSurface(SDL_Surface *handle);

    [[nodiscard]] SDL_Surface *Get() const noexcept override;
};

} // namespace sdl
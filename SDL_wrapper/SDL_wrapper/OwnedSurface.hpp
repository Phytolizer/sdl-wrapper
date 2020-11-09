#pragma once

#include "Surface.hpp"
#include "pch.h"

namespace sdl
{

constexpr auto OWNED_SURFACE_DELETER = [](SDL_Surface *handle) {
    if (handle != nullptr)
    {
        SDL_FreeSurface(handle);
    }
};

class OwnedSurface final : public Surface
{
    std::unique_ptr<SDL_Surface, decltype(OWNED_SURFACE_DELETER)> m_handle;

  public:
    explicit OwnedSurface(SDL_Surface *handle);

    [[nodiscard]] SDL_Surface *Get() const noexcept override;
};

} // namespace sdl
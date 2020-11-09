#pragma once

#include "Texture.hpp"

namespace sdl
{

class RefTexture final : public Texture
{
    SDL_Texture *m_handle;

  public:
    explicit RefTexture(SDL_Texture *handle);
    [[nodiscard]] SDL_Texture *Get() const noexcept override;
};
} // namespace sdl

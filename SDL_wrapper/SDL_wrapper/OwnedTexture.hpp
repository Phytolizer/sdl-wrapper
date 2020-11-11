#pragma once
#include "BlendMode.hpp"
#include "Texture.hpp"
#include "pch.h"

namespace sdl
{

class Renderer;
class Surface;

class OwnedTexture final : public Texture
{
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> m_handle;

  public:
    OwnedTexture(const Renderer &renderer, TextureAttributes &&attributes);
    OwnedTexture(const Renderer &renderer, const Surface &surface);

    [[nodiscard]] SDL_Texture *Get() const noexcept override;
};
} // namespace sdl
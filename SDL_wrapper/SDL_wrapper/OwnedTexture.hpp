#pragma once
#include "BlendMode.hpp"
#include "pch.h"
#include "Texture.hpp"

namespace sdl
{

class Renderer;
class Surface;

constexpr auto TEXTURE_DELETER = [](SDL_Texture *texture) {
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
    }
};

class OwnedTexture final : public Texture
{
    std::unique_ptr<SDL_Texture, decltype(TEXTURE_DELETER)> m_handle;

  public:
    OwnedTexture(const Renderer &renderer, TextureAttributes &&attributes);
    OwnedTexture(const Renderer &renderer, const Surface &surface);

    [[nodiscard]] SDL_Texture *Get() const noexcept override;
};
} // namespace sdl
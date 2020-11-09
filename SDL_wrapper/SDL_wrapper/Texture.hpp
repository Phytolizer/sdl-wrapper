#pragma once
#include "BlendMode.hpp"
#include "pch.h"

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

struct TextureAttributes
{
    Uint32 format;
    int access;
    int w;
    int h;
};

class Texture
{
    std::unique_ptr<SDL_Texture, decltype(TEXTURE_DELETER)> m_handle;

  public:
    Texture(const Renderer &renderer, TextureAttributes &&attributes);
    Texture(const Renderer &renderer, const Surface &surface);

    [[nodiscard]] Uint8 GetAlphaMod() const;
    [[nodiscard]] BlendMode GetBlendMode() const;
    [[nodiscard]] SDL_Color GetColorMod() const;
    [[nodiscard]] TextureAttributes Query() const;
    // Wrapper for SDL_SetTextureAlphaMod
    void SetAlphaMod(Uint8 alpha);
    [[nodiscard]] SDL_Texture *Get() const noexcept;
};
} // namespace sdl
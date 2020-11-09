#pragma once

#include "pch.h"

namespace sdl
{

enum class BlendMode;

struct TextureAttributes
{
    Uint32 format;
    int access;
    int w;
    int h;
};

class Texture
{
    std::unique_ptr<Texture> m_texture;

  protected:
    Texture() = default;

  public:
    explicit Texture(std::unique_ptr<Texture> &&handle);
    virtual ~Texture() = default;
    Texture(const Texture &) = delete;
    Texture(Texture &&) = default;
    Texture &operator=(const Texture &) = delete;
    Texture &operator=(Texture &&) = default;

    [[nodiscard]] Uint8 GetAlphaMod() const;
    [[nodiscard]] BlendMode GetBlendMode() const;
    [[nodiscard]] SDL_Color GetColorMod() const;
    [[nodiscard]] TextureAttributes Query() const;
    // Wrapper for SDL_SetTextureAlphaMod
    void SetAlphaMod(Uint8 alpha);
    [[nodiscard]] virtual SDL_Texture *Get() const noexcept;
};

} // namespace sdl

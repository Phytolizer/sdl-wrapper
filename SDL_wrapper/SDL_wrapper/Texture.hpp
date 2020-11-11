#pragma once

#include "pch.h"

namespace sdl
{

enum class BlendMode;
class Renderer;
class Surface;

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
    std::optional<TextureAttributes> m_cachedQuery;

  protected:
    Texture() = default;

  public:
    explicit Texture(std::unique_ptr<Texture> &&handle);
    explicit Texture(const Renderer &renderer, const Surface &surface);
    virtual ~Texture() = default;
    Texture(const Texture &) = delete;
    Texture(Texture &&) = default;
    Texture &operator=(const Texture &) = delete;
    Texture &operator=(Texture &&) = default;

    [[nodiscard]] Uint8 GetAlphaMod() const;
    [[nodiscard]] BlendMode GetBlendMode() const;
    [[nodiscard]] SDL_Color GetColorMod() const;
    // non-const due to implementation details
    [[nodiscard]] TextureAttributes Query();
    // Wrapper for SDL_SetTextureAlphaMod
    void SetAlphaMod(Uint8 alpha);
    void SetBlendMode(BlendMode mode);
    void SetColorMod(const SDL_Color &mod);
    [[nodiscard]] virtual SDL_Texture *Get() const noexcept;
};

} // namespace sdl

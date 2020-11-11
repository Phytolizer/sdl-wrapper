#pragma once

#include "pch.h"

struct LTexture
{
    sdl::Texture m_texture;

  public:
    LTexture(const sdl::Image::Context &imgContext,
             const sdl::Renderer &renderer, std::string_view path);
    LTexture(const sdl::Renderer &renderer, const sdl::Surface &surface);

    void RenderTo(sdl::Renderer &renderer, sdl::point p,
                  std::optional<sdl::rect> clip);
    void SetColor(const SDL_Color &c);
    void SetAlphaMod(Uint8 mod);
    void SetBlendMode(sdl::BlendMode mode);
};

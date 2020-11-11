#include "LTexture.hpp"

LTexture::LTexture(const sdl::Image::Context &imgContext,
                   const sdl::Renderer &renderer, std::string_view path)
    : m_texture{renderer, imgContext.Load(path)}
{
}

LTexture::LTexture(const sdl::Renderer &renderer, const sdl::Surface &surface)
    : m_texture{renderer, surface}
{
}

void LTexture::RenderTo(sdl::Renderer &renderer, sdl::point p,
                        std::optional<sdl::rect> clip)
{
    auto renderQuad =
        sdl::rect{p.x, p.y, m_texture.Query().w, m_texture.Query().h};
    if (clip.has_value())
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    renderer.Copy(m_texture, std::move(clip), {renderQuad});
}

void LTexture::SetColor(const SDL_Color &c)
{
    m_texture.SetColorMod(c);
}

void LTexture::SetAlphaMod(const Uint8 mod)
{
    m_texture.SetAlphaMod(mod);
}

void LTexture::SetBlendMode(const sdl::BlendMode mode)
{
    m_texture.SetBlendMode(mode);
}

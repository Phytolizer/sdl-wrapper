#include "Texture.hpp"

#include "Renderer.hpp"
#include "Surface.hpp"

sdl::Texture::Texture(const Renderer &renderer, TextureAttributes &&attributes)
    : m_handle(SDL_CreateTexture(renderer.Get(), attributes.format,
                                 attributes.access, attributes.w, attributes.h))
{
    if (!m_handle)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("SDL texture creation failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

sdl::Texture::Texture(const Renderer &renderer, const Surface &surface)
    : m_handle(SDL_CreateTextureFromSurface(renderer.Get(), surface.Get()))
{
    if (!m_handle)
    {
        throw std::runtime_error{
            Helpers::StringBuilder()
                .Add("Creating SDL texture from surface failed: ")
                .Add(SDL_GetError())
                .Build()};
    }
}

Uint8 sdl::Texture::GetAlphaMod() const
{
    Uint8 alphaMod{};
    if (SDL_GetTextureAlphaMod(m_handle.get(), &alphaMod) != 0)
    {
        throw std::runtime_error{
            Helpers::StringBuilder()
                .Add("Getting SDL texture alpha mod failed: ")
                .Add(SDL_GetError())
                .Build()};
    }
    return alphaMod;
}

sdl::BlendMode sdl::Texture::GetBlendMode() const
{
    SDL_BlendMode mode{};
    if (SDL_GetTextureBlendMode(m_handle.get(), &mode) != 0)
    {
        throw std::runtime_error{
            Helpers::StringBuilder()
                .Add("Getting SDL texture blend mode failed: ")
                .Add(SDL_GetError())
                .Build()};
    }
    return BlendModeFromSdl(mode);
}

SDL_Color sdl::Texture::GetColorMod() const
{
    SDL_Color color{0, 0, 0, 0};
    if (SDL_GetTextureColorMod(m_handle.get(), &color.r, &color.g, &color.b) !=
        0)
    {
        throw std::runtime_error{
            Helpers::StringBuilder()
                .Add("Getting SDL texture color mod failed: ")
                .Add(SDL_GetError())
                .Build()};
    }
    return color;
}

sdl::TextureAttributes sdl::Texture::Query() const
{
    TextureAttributes attributes{};
    if (SDL_QueryTexture(m_handle.get(), &attributes.format, &attributes.access,
                         &attributes.w, &attributes.h) != 0)
    {
        throw std::runtime_error{
            Helpers::StringBuilder()
                .Add("Querying SDL texture attributes failed: ")
                .Add(SDL_GetError())
                .Build()};
    }

    return attributes;
}

// ReSharper disable once CppMemberFunctionMayBeConst
// not const because even though the handle is const-accessible, we shouldn't be
// able to set the alpha mod on a const Texture
//
// this logic also applies to the other setters
void sdl::Texture::SetAlphaMod(const Uint8 alpha)
{
    if (SDL_SetTextureAlphaMod(m_handle.get(), alpha) != 0)
    {
        throw std::runtime_error{
            Helpers::StringBuilder()
                .Add("Setting SDL texture alpha mod failed: ")
                .Add(SDL_GetError())
                .Build()};
    }
}

SDL_Texture *sdl::Texture::Get() const noexcept
{
    return m_handle.get();
}

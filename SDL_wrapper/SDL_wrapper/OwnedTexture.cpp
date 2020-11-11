#include "OwnedTexture.hpp"

#include "Renderer.hpp"
#include "Surface.hpp"

sdl::OwnedTexture::OwnedTexture(const Renderer &renderer,
                                TextureAttributes &&attributes)
    : m_handle(SDL_CreateTexture(renderer.Get(), attributes.format,
                                 attributes.access, attributes.w, attributes.h),
               SDL_DestroyTexture)
{
    if (!m_handle)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("SDL texture creation failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

sdl::OwnedTexture::OwnedTexture(const Renderer &renderer,
                                const Surface &surface)
    : m_handle(SDL_CreateTextureFromSurface(renderer.Get(), surface.Get()),
               SDL_DestroyTexture)
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

SDL_Texture *sdl::OwnedTexture::Get() const noexcept
{
    return m_handle.get();
}

#include "Renderer.hpp"

#include "Surface.hpp"
#include "Texture.hpp"
#include "Window.hpp"

namespace sdl
{

Renderer::Renderer(const sdl::Window &window, const int index,
                   const Uint32 flags)
    : m_handle(SDL_CreateRenderer(window.Get(), index, flags))
{
    if (!m_handle)
    {
        throw std::runtime_error(Helpers::StringBuilder()
                                     .Add("Creating SDL renderer failed: ")
                                     .Add(SDL_GetError())
                                     .Build());
    }
}

SDL_Renderer *Renderer::Get() const noexcept
{
    return m_handle.get();
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::Clear()
{
    if (SDL_RenderClear(m_handle.get()) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Clearing renderer failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::Present() noexcept
{
    SDL_RenderPresent(m_handle.get());
}

Renderer::Renderer(const Surface &surface)
    : m_handle(SDL_CreateSoftwareRenderer(surface.Get()))
{
    if (!m_handle)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Creating software renderer failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

void Renderer::Copy(const Texture &texture, std::optional<SDL_Rect> &&srcRect,
                    std::optional<SDL_Rect> &&destRect) const
{
    SDL_Rect *s = nullptr;
    if (srcRect.has_value())
    {
        s = &*srcRect;
    }
    SDL_Rect *d = nullptr;
    if (destRect.has_value())
    {
        s = &*destRect;
    }
    if (SDL_RenderCopy(m_handle.get(), texture.Get(), s, d) != 0)
    {
        throw std::runtime_error{
            Helpers::StringBuilder()
                .Add("Copying texture to renderer failed: ")
                .Add(SDL_GetError())
                .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::SetDrawColor(const SDL_Color &color)
{
    if (SDL_SetRenderDrawColor(m_handle.get(), color.r, color.g, color.b, color.a) != 0)
    {
        throw std::runtime_error{
            Helpers::StringBuilder()
                .Add("Setting renderer draw color failed: ")
                .Add(SDL_GetError())
                .Build()};
    }
    
}

} // namespace sdl
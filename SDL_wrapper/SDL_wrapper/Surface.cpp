#include "Surface.hpp"

#include "OwnedSurface.hpp"

namespace sdl
{
Surface::Surface(std::unique_ptr<Surface> &&handle)
    : m_surface(std::move(handle))
{
    if (m_surface->Get() == nullptr)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("SDL surface creation failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

Surface Surface::LoadBmp(const Context & /*context*/,
                         const std::string_view fileName)
{
    return Surface{
        std::make_unique<OwnedSurface>(SDL_LoadBMP(fileName.data()))};
}

SDL_Surface *Surface::Get() const noexcept
{
    return m_surface->Get();
}

SDL_PixelFormat *Surface::Format() const
{
    return Get()->format;
}

void Surface::Blit(std::optional<SDL_Rect> srcRect, const Surface &destination,
                   std::optional<SDL_Rect> destRect) const
{
    SDL_Rect *s = nullptr;
    if (srcRect.has_value())
    {
        s = &*srcRect;
    }
    SDL_Rect *d = nullptr;
    if (destRect.has_value())
    {
        d = &*destRect;
    }
    std::cout << "m_surface: " << m_surface
              << "\ndestination.Get(): " << destination.Get() << "\n";
    if (SDL_BlitSurface(m_surface->Get(), s, destination.Get(), d) != 0)
    {
        throw std::runtime_error(Helpers::StringBuilder()
                                     .Add("Blitting surface failed: ")
                                     .Add(SDL_GetError())
                                     .Build());
    }
}

void Surface::SetColorKey(std::optional<SDL_Color> key)
{
    int code;
    if (key.has_value())
    {
        code = SDL_SetColorKey(
            m_surface->Get(), SDL_TRUE,
            SDL_MapRGB(m_surface->Format(), key->r, key->g, key->b));
    }
    else
    {
        code = SDL_SetColorKey(m_surface->Get(), SDL_FALSE, 0);
    }

    if (code != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder{}
                                     .Add("Setting surface color key failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

} // namespace sdl
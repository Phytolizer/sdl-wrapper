#include "Surface.hpp"
#include "OwnedSurface.hpp"

namespace sdl
{

Surface::Surface(SDL_Surface *handle) : m_handle(handle)
{
    if (handle == nullptr)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("SDL surface creation failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}
OwnedSurface Surface::LoadBmp(const Context &context,
                              const std::string_view fileName)
{
    return OwnedSurface(SDL_LoadBMP(fileName.data()));
}
SDL_Surface *Surface::Get() const noexcept
{
    return m_handle;
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
    std::cout << "m_handle: " << m_handle
              << "\ndestination.Get(): " << destination.Get() << "\n";
    if (SDL_BlitSurface(m_handle, s, destination.Get(), d) != 0)
    {
        throw std::runtime_error(Helpers::StringBuilder()
                                     .Add("Blitting surface failed: ")
                                     .Add(SDL_GetError())
                                     .Build());
    }
}

} // namespace sdl
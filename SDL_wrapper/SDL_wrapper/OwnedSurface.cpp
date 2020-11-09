#include "OwnedSurface.hpp"

namespace sdl
{

OwnedSurface::OwnedSurface(SDL_Surface *handle) : m_handle(handle)
{
}

SDL_Surface *OwnedSurface::Get() const noexcept
{
    return m_handle.get();
}

} // namespace sdl
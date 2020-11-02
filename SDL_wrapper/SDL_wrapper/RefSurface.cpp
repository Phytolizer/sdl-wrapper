#include "RefSurface.hpp"

namespace sdl
{
RefSurface::RefSurface(SDL_Surface *handle) : m_handle(handle)
{
}
SDL_Surface *RefSurface::Get() const noexcept
{
    return m_handle;
}
} // namespace sdl
#include "OwnedSurface.hpp"

namespace sdl
{
OwnedSurface::OwnedSurface(SDL_Surface *handle) : Surface(handle)
{
}
OwnedSurface::~OwnedSurface()
{
    if (m_handle != nullptr)
    {
        SDL_FreeSurface(m_handle);
    }
}
OwnedSurface::OwnedSurface(OwnedSurface &&other) noexcept
    : Surface(other.m_handle)
{
    other.m_handle = nullptr;
}
OwnedSurface &OwnedSurface::operator=(OwnedSurface &&other) noexcept
{
    if (&other != this)
    {
        if (m_handle != nullptr)
        {
            SDL_FreeSurface(m_handle);
        }
        m_handle = other.m_handle;
        other.m_handle = nullptr;
    }
    return *this;
}
} // namespace sdl
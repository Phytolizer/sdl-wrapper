#include "OwnedSurface.hpp"

namespace sdl
{

OwnedSurface::OwnedSurface(SDL_Surface *handle) : m_handle(handle)
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
    : m_handle(other.m_handle)
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

SDL_Surface *OwnedSurface::Get() const noexcept
{
    return m_handle;
}

} // namespace sdl
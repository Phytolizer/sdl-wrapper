#include "RefTexture.hpp"


sdl::RefTexture::RefTexture(SDL_Texture *handle) : m_handle(handle)
{
}

SDL_Texture * sdl::RefTexture::Get() const noexcept
{
    return m_handle;
}

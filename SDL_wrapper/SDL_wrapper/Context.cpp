#include "Context.hpp"

sdl::Context::Context() : m_active(true)
{
    if (SDL_Init(0) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("SDL failed to initialize: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

sdl::Context::~Context() noexcept
{
    if (m_active)
    {
        SDL_Quit();
    }
}

sdl::Context::Context(Context &&other) noexcept : m_active(other.m_active)
{
    other.m_active = false;
}

sdl::Context &sdl::Context::operator=(sdl::Context &&other) noexcept
{
    if (&other != this)
    {
        m_active = other.m_active;
        other.m_active = false;
    }
    return *this;
}

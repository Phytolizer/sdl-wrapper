#include "Context.hpp"
#include "VideoSubsystem.hpp"

sdl::Context::Context()
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

// ReSharper disable once CppMemberFunctionMayBeStatic
void sdl::Context::SetHint(const std::string_view name,
                           const std::string_view value) const
{
    if (SDL_SetHint(name.data(), value.data()) == SDL_FALSE)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Setting SDL hint ")
                                     .Add(name)
                                     .Add(" failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

sdl::VideoSubsystem sdl::Context::Video() const
{
    return VideoSubsystem(*this);
}

// ReSharper disable once CppMemberFunctionMayBeStatic
std::optional<SDL_Event> sdl::Context::PollEvent() const noexcept
{
    SDL_Event e;
    if (SDL_PollEvent(&e) != 0)
    {
        return {e};
    }
    return {};
}

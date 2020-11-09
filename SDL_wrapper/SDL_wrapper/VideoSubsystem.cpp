#include "VideoSubsystem.hpp"
#include "WindowBuilder.hpp"

sdl::VideoSubsystem::VideoSubsystem(const Context & /*context*/)
{
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0)
    {
        throw std::runtime_error{
            Helpers::StringBuilder()
                .Add("SDL video subsystem failed to initialize: ")
                .Add(SDL_GetError())
                .Build()};
    }
}

sdl::VideoSubsystem::~VideoSubsystem() noexcept
{
    if (m_active)
    {
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }
}

sdl::VideoSubsystem::VideoSubsystem(VideoSubsystem &&other) noexcept
    : m_active(other.m_active)
{
}

sdl::VideoSubsystem &sdl::VideoSubsystem::operator=(
    sdl::VideoSubsystem &&other) noexcept
{
    if (&other != this)
    {
        m_active = other.m_active;
        other.m_active = false;
    }
    return *this;
}

sdl::WindowBuilder sdl::VideoSubsystem::CreateWindow(std::string_view title,
    int x, int y, int w, int h) const
{
    return WindowBuilder(title, x, y, w, h);
}

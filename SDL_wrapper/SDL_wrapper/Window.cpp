#include "Window.hpp"

#include "RefSurface.hpp"
#include "WindowBuilder.hpp"

namespace sdl
{

Window::Window(const std::string_view title, const int x, const int y,
               const int w, const int h, const Uint32 flags)
    : m_handle(SDL_CreateWindow(title.data(), x, y, w, h, flags))
{
    if (m_handle == nullptr)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("SDL window creation failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

Window::~Window() noexcept
{
    if (m_handle != nullptr)
    {
        SDL_DestroyWindow(m_handle);
    }
}

Window::Window(Window &&other) noexcept : m_handle(other.m_handle)
{
    other.m_handle = nullptr;
}

Window &Window::operator=(Window &&other) noexcept
{
    if (&other != this)
    {
        if (m_handle != nullptr)
        {
            SDL_DestroyWindow(m_handle);
        }
        m_handle = other.m_handle;
        other.m_handle = nullptr;
    }
    return *this;
}

Surface Window::GetSurface() const
{
    return Surface{
        std::make_unique<RefSurface>(SDL_GetWindowSurface(m_handle))};
}

void Window::UpdateSurface() const
{
    if (SDL_UpdateWindowSurface(m_handle) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Updating window surface failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

SDL_Window *Window::Get() const noexcept
{
    return m_handle;
}

} // namespace sdl
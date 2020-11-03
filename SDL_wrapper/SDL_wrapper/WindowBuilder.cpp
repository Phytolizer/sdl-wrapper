#include "WindowBuilder.hpp"

namespace sdl
{
WindowBuilder::WindowBuilder()
{
}

WindowBuilder &WindowBuilder::Fullscreen() noexcept
{
    m_flags |= SDL_WINDOW_FULLSCREEN;
    return *this;
}

WindowBuilder &WindowBuilder::FullscreenDesktop() noexcept
{
    m_flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    return *this;
}

WindowBuilder &WindowBuilder::OpenGl() noexcept
{
    m_flags |= SDL_WINDOW_OPENGL;
    return *this;
}

WindowBuilder &WindowBuilder::Vulkan() noexcept
{
    m_flags |= SDL_WINDOW_VULKAN;
    return *this;
}

WindowBuilder &WindowBuilder::Shown() noexcept
{
    m_flags |= SDL_WINDOW_SHOWN;
    return *this;
}

WindowBuilder &WindowBuilder::Hidden() noexcept
{
    m_flags |= SDL_WINDOW_HIDDEN;
    return *this;
}

WindowBuilder &WindowBuilder::Borderless() noexcept
{
    m_flags |= SDL_WINDOW_BORDERLESS;
    return *this;
}

WindowBuilder &WindowBuilder::Resizable() noexcept
{
    m_flags |= SDL_WINDOW_RESIZABLE;
    return *this;
}

WindowBuilder &WindowBuilder::Minimized() noexcept
{
    m_flags |= SDL_WINDOW_MINIMIZED;
    return *this;
}

WindowBuilder &WindowBuilder::Maximized() noexcept
{
    m_flags |= SDL_WINDOW_MAXIMIZED;
    return *this;
}

WindowBuilder &WindowBuilder::InputGrabbed() noexcept
{
    m_flags |= SDL_WINDOW_INPUT_GRABBED;
    return *this;
}

WindowBuilder &WindowBuilder::InputFocus() noexcept
{
    m_flags |= SDL_WINDOW_INPUT_FOCUS;
    return *this;
}

WindowBuilder &WindowBuilder::MouseFocus() noexcept
{
    m_flags |= SDL_WINDOW_MOUSE_FOCUS;
    return *this;
}

WindowBuilder &WindowBuilder::Foreign() noexcept
{
    m_flags |= SDL_WINDOW_FOREIGN;
    return *this;
}

WindowBuilder &WindowBuilder::AllowHighDpi() noexcept
{
    m_flags |= SDL_WINDOW_ALLOW_HIGHDPI;
    return *this;
}

WindowBuilder &WindowBuilder::MouseCapture() noexcept
{
    m_flags |= SDL_WINDOW_MOUSE_CAPTURE;
    return *this;
}

WindowBuilder &WindowBuilder::AlwaysOnTop() noexcept
{
    m_flags |= SDL_WINDOW_ALWAYS_ON_TOP;
    return *this;
}

WindowBuilder &WindowBuilder::SkipTaskbar() noexcept
{
    m_flags |= SDL_WINDOW_SKIP_TASKBAR;
    return *this;
}

WindowBuilder &WindowBuilder::Utility() noexcept
{
    m_flags |= SDL_WINDOW_UTILITY;
    return *this;
}

WindowBuilder &WindowBuilder::Tooltip() noexcept
{
    m_flags |= SDL_WINDOW_TOOLTIP;
    return *this;
}

WindowBuilder &WindowBuilder::PopupMenu() noexcept
{
    m_flags |= SDL_WINDOW_POPUP_MENU;
    return *this;
}

Window WindowBuilder::Build(const VideoSubsystem &videoSubsystem,
                            const std::string_view title, const int x,
                            const int y, const int w, const int h) const
{
    return Window(videoSubsystem, title, x, y, w, h, m_flags);
}
} // namespace sdl
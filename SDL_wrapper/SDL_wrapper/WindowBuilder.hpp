#pragma once

#include "Window.hpp"
#include "pch.h"

namespace sdl
{

class WindowBuilder
{
    Uint32 m_flags{0};
    std::string_view m_title;
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    WindowBuilder(std::string_view title, int x, int y, int w, int h);
    friend class VideoSubsystem;

  public:
    WindowBuilder &Fullscreen() noexcept;
    WindowBuilder &FullscreenDesktop() noexcept;
    WindowBuilder &OpenGl() noexcept;
    WindowBuilder &Vulkan() noexcept;
    WindowBuilder &Shown() noexcept;
    WindowBuilder &Hidden() noexcept;
    WindowBuilder &Borderless() noexcept;
    WindowBuilder &Resizable() noexcept;
    WindowBuilder &Minimized() noexcept;
    WindowBuilder &Maximized() noexcept;
    WindowBuilder &InputGrabbed() noexcept;
    WindowBuilder &InputFocus() noexcept;
    WindowBuilder &MouseFocus() noexcept;
    WindowBuilder &Foreign() noexcept;
    WindowBuilder &AllowHighDpi() noexcept;
    WindowBuilder &MouseCapture() noexcept;
    WindowBuilder &AlwaysOnTop() noexcept;
    WindowBuilder &SkipTaskbar() noexcept;
    WindowBuilder &Utility() noexcept;
    WindowBuilder &Tooltip() noexcept;
    WindowBuilder &PopupMenu() noexcept;
    Window Build() const;
};

} // namespace sdl

#pragma once

#include "pch.h"
#include "VideoSubsystem.hpp"

namespace sdl
{

class WindowBuilder;
class Surface;

class Window
{
    SDL_Window *m_handle;

    Window(std::string_view title, int x,
           int y, int w, int h, Uint32 flags);
    friend class WindowBuilder;
  public:
    ~Window() noexcept;
    Window(const Window &) = delete;
    Window(Window &&other) noexcept;
    Window &operator=(const Window &) = delete;
    Window &operator=(Window &&other) noexcept;
    [[nodiscard]] Surface GetSurface() const;
    void UpdateSurface() const;
    [[nodiscard]] SDL_Window *Get() const noexcept;
};
} // namespace sdl

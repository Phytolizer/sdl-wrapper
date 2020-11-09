#pragma once

#include "Context.hpp"

namespace sdl
{

class WindowBuilder;

class VideoSubsystem
{
    bool m_active{true};
    explicit VideoSubsystem(const Context &context);
    friend class Context;

  public:
    ~VideoSubsystem() noexcept;
    VideoSubsystem(const VideoSubsystem &) = delete;
    VideoSubsystem(VideoSubsystem &&other) noexcept;
    VideoSubsystem &operator=(const VideoSubsystem &) = delete;
    VideoSubsystem &operator=(VideoSubsystem &&other) noexcept;

    WindowBuilder CreateWindow(std::string_view title, int x, int y, int w,
                               int h) const;
};
} // namespace sdl
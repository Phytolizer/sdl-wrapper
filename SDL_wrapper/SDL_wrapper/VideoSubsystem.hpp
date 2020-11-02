#pragma once

#include "pch.h"
#include "Context.hpp"

namespace sdl
{
class VideoSubsystem
{
    bool m_active;

  public:
    explicit VideoSubsystem(const Context &context);
    ~VideoSubsystem() noexcept;
    VideoSubsystem(const VideoSubsystem &) = delete;
    VideoSubsystem(VideoSubsystem &&other) noexcept;
    VideoSubsystem &operator=(const VideoSubsystem &) = delete;
    VideoSubsystem &operator=(VideoSubsystem &&other) noexcept;
};
} // namespace sdl
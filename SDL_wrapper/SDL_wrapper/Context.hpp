#pragma once

#include "pch.h"

namespace sdl
{

class VideoSubsystem;

class Context
{
    bool m_active{true};

  public:
    Context();
    ~Context() noexcept;
    Context(const Context &) = delete;
    Context(Context &&other) noexcept;
    Context &operator=(const Context &) = delete;
    Context &operator=(Context &&other) noexcept;

    void SetHint(std::string_view name, std::string_view value) const;

    [[nodiscard]] VideoSubsystem Video() const;
    /// Alias for SDL_PollEvent
    [[nodiscard]] std::optional<SDL_Event> PollEvent() const noexcept;
};
} // namespace sdl
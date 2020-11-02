#pragma once

#include "pch.h"

namespace sdl
{
class Context
{
    bool m_active;

  public:
    Context();
    ~Context() noexcept;
    Context(const Context &) = delete;
    Context(Context &&other) noexcept;
    Context &operator=(const Context &) = delete;
    Context &operator=(Context &&other) noexcept;
};
} // namespace sdl
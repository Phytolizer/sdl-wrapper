#pragma once

#include "Flags.hpp"
#include "pch.h"
#include "../Surface.hpp"

namespace sdl::Image
{

class Context
{
    bool m_active{true};
    InitFlag m_flags{InitFlag::none};

  public:
    explicit Context(InitFlag flags);
    ~Context();
    Context(const Context &) = delete;
    Context(Context &&other) noexcept;
    Context &operator=(const Context &) = delete;
    Context &operator=(Context &&other) noexcept;
    [[nodiscard]] Surface Load(std::string_view fileName) const;
};

} // namespace sdl::Image
#pragma once

#include "pch.h"

namespace Helpers
{
template <typename T>
concept OutputStreamable = requires(std::ostream &os, T arg)
{
    os << arg;
};
template <typename Derived> class OutputStream
{
    std::ostream &m_underlying;

  public:
    OutputStream(std::ostream &underlying) : m_underlying(underlying)
    {
    }

    template <OutputStreamable T> Derived &Add(T value)
    {
        m_underlying << value;
        return static_cast<Derived &>(*this);
    }
};
} // namespace Helpers

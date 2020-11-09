#pragma once

#include "pch.h"

namespace Helpers
{
template <typename T>
concept output_streamable = requires(std::ostream &os, T arg)
{
    os << arg;
};

template <typename Derived> class IOutputStream
{
    std::ostream &m_underlying;

  public:
    explicit IOutputStream(std::ostream &underlying) : m_underlying(underlying)
    {
    }

    template <output_streamable T> Derived &Add(T value)
    {
        m_underlying << value;
        return static_cast<Derived &>(*this);
    }
};

} // namespace Helpers

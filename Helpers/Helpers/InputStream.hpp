#pragma once

#include "pch.h"

namespace Helpers
{

template <typename T>
concept input_streamable = requires(std::istream &is, T arg)
{
    T();
    is >> arg;
};

class InputStream
{
    std::istream &m_underlying;

  public:
    explicit InputStream(std::istream &underlying);

    template <input_streamable T> T Get()
    {
        T out;
        m_underlying >> out;
        return out;
    }
};

} // namespace Helpers
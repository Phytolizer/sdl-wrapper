#pragma once

#include "IOutputStream.hpp"
#include "pch.h"

namespace Helpers
{
class StringBuilder : public IOutputStream<StringBuilder>
{
    std::stringstream m_ss;

  public:
    StringBuilder();

    [[nodiscard]] std::string Build() const;
};

template <output_streamable T>
[[nodiscard]] std::string BuildStringRecursive(
    gsl::not_null<StringBuilder *> builder, T final)
{
    builder->Add(final);
    return builder->Build();
}

template <output_streamable T, output_streamable... Args>
[[nodiscard]] std::string BuildStringRecursive(
    gsl::not_null<StringBuilder *> builder, T first, Args... rest)
{
    builder->Add(first);
    return BuildStringRecursive(builder, rest...);
}

template <output_streamable T> [[nodiscard]] std::string BuildString(T only)
{
    StringBuilder builder;
    builder.Add(only);
    return builder.Build();
}

template <output_streamable T, output_streamable... Args>
[[nodiscard]] std::string BuildString(T first, Args... rest)
{
    StringBuilder builder;
    builder.Add(first);
    return BuildStringRecursive(&builder, rest...);
}
} // namespace Helpers
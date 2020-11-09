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

template <output_streamable T, output_streamable... Args>
std::string BuildString(T first, Args... rest)
{
    StringBuilder builder;
    builder.Add(first);

}
} // namespace Helpers
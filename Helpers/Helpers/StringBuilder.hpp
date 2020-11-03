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
} // namespace Helpers
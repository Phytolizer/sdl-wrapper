#pragma once

#include "OutputStream.hpp"
#include "pch.h"

namespace Helpers
{
class StringBuilder : public OutputStream<StringBuilder>
{
    std::stringstream m_ss;

  public:
    StringBuilder();

    std::string Build();
};
} // namespace Helpers
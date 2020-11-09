#pragma once

#include "IOutputStream.hpp"

namespace Helpers
{

class OutputStream : public IOutputStream<OutputStream>
{
public:
    explicit OutputStream(std::ostream &os) noexcept;
};

extern OutputStream STD_OUT;
extern OutputStream STD_ERR;

}

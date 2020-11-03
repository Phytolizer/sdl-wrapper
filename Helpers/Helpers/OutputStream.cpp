#include "OutputStream.hpp"

Helpers::OutputStream::OutputStream(std::ostream &os) noexcept
    : IOutputStream(os)
{
}

Helpers::OutputStream STD_OUT{std::cout};
Helpers::OutputStream STD_ERR{std::cerr};


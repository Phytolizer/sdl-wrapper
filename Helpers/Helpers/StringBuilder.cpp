#include "StringBuilder.hpp"

Helpers::StringBuilder::StringBuilder() : IOutputStream(m_ss)
{
}

std::string Helpers::StringBuilder::Build() const
{
    return m_ss.str();
}

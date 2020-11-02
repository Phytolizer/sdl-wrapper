#include "StringBuilder.hpp"

Helpers::StringBuilder::StringBuilder() : OutputStream(m_ss), m_ss()
{
}

std::string Helpers::StringBuilder::Build()
{
    return m_ss.str();
}

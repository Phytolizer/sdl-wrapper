#include "InputStream.hpp"

Helpers::InputStream::InputStream(std::istream &underlying)
    : m_underlying(underlying)
{
}

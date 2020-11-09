#include "Context.hpp"

#include "../RefSurface.hpp"
#include "Flags.hpp"

namespace sdl::Image
{
Context::Context(const InitFlag flags) : m_flags(flags)
{
    if (IMG_Init(static_cast<int>(flags)) != static_cast<int>(flags))
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("SDL_image initialization failed: ")
                                     .Add(IMG_GetError())
                                     .Build()};
    }
}

Context::~Context()
{
    if (m_active)
    {
        IMG_Quit();
    }
}

Context::Context(Context &&other) noexcept : m_active(other.m_active)
{
    other.m_active = false;
}

Context &Context::operator=(Context &&other) noexcept
{
    if (&other != this)
    {
        m_active = other.m_active;
        other.m_active = false;
    }
    return *this;
}

Surface Context::Load(const std::string_view fileName) const
{
    auto *ptr = IMG_Load(fileName.data());
    if (ptr == nullptr)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Loading image ")
                                     .Add(fileName)
                                     .Add(" failed: ")
                                     .Add(IMG_GetError())
                                     .Build()};
    }
    return Surface{std::make_unique<RefSurface>(ptr)};
}
} // namespace sdl::Image

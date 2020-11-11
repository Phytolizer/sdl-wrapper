#include "SurfaceBuilder.hpp"

namespace sdl
{

SurfaceBuilder::SurfaceBuilder(std::unique_ptr<Surface> &&surface)
    : m_surface{std::move(surface)}
{
}

SurfaceBuilder &SurfaceBuilder::WithColorKey(SDL_Color key) noexcept
{
    m_surface.SetColorKey({key});
    return *this;
}

Surface &&SurfaceBuilder::Build() noexcept
{
    return std::move(m_surface);
}

} // namespace sdl
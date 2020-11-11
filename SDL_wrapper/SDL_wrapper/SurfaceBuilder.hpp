#pragma once
#include "Surface.hpp"

namespace sdl::Image
{
class Context;
}

namespace sdl
{

class SurfaceBuilder
{
    // the surface to modify
    sdl::Surface m_surface;

    SurfaceBuilder(std::unique_ptr<Surface> &&surface);
    // can create SurfaceBuilder instances via LoadBuilder(std::string_view)
    friend class Image::Context;

  public:
    // Set the color key for the surface.
    SurfaceBuilder &WithColorKey(SDL_Color key) noexcept;

    // Consume the SurfaceBuilder and get a Surface out.
    Surface &&Build() noexcept;
};

} // namespace sdl
#include "Renderer.hpp"
#include "Helpers/StringBuilder.hpp"
#include "SDL2/SDL_error.h"
#include <SDL2_gfxPrimitives.h>
#include <stdexcept>

namespace sdl::Gfx
{
Renderer::Renderer(SDL_Renderer *handle) : m_handle(handle)
{
    if (handle == nullptr)
    {
        throw std::runtime_error{
            "Cannot construct sdl::Gfx::Renderer with null handle"};
    }
}
void Renderer::Pixel(Sint16 x, Sint16 y, SDL_Color color)
{
    if (pixelRGBA(m_handle, x, y, color.r, color.g, color.b, color.a) != 0)
    {
        throw std::runtime_error(
            Helpers::BuildString("Couldn't draw pixel: ", SDL_GetError()));
    }
}
void Renderer::HorizontalLine(Sint16 x1, Sint16 x2, Sint16 y, SDL_Color color)
{
    if (hlineRGBA(m_handle, x1, x2, y, color.r, color.g, color.b, color.a) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw horizontal line: ", SDL_GetError()));
    }
}
void Renderer::VerticalLine(Sint16 x, Sint16 y1, Sint16 y2, SDL_Color color)
{
    if (vlineRGBA(m_handle, x, y1, y2, color.r, color.g, color.b, color.a) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw vertical line: ", SDL_GetError()));
    }
}
void Renderer::Rectangle(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                         SDL_Color color)
{
    if (rectangleRGBA(m_handle, x1, y1, x2, y2, color.r, color.g, color.b,
                      color.a) != 0)
    {
        throw std::runtime_error(
            Helpers::BuildString("Couldn't draw rectangle: ", SDL_GetError()));
    }
}
void Renderer::RoundedRectangle(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                                Sint16 radius, SDL_Color color)
{
    if (roundedRectangleRGBA(m_handle, x1, y1, x2, y2, radius, color.r, color.g,
                             color.b, color.a) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw rounded rectangle: ", SDL_GetError()));
    }
}
void Renderer::Box(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, SDL_Color color)
{
    if (boxRGBA(m_handle, x1, y1, x2, y2, color.r, color.g, color.b, color.a) !=
        0)
    {
        throw std::runtime_error(
            Helpers::BuildString("Couldn't draw box: ", SDL_GetError()));
    }
}
void Renderer::RoundedBox(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                          Sint16 radius, SDL_Color color)
{
    if (roundedBoxRGBA(m_handle, x1, y1, x2, y2, radius, color.r, color.g,
                       color.b, color.a) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw rounded box: ", SDL_GetError()));
    }
}
void Renderer::Line(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, SDL_Color color)
{
    if (lineRGBA(m_handle, x1, y1, x2, y2, color.r, color.g, color.b,
                 color.a) != 0)
    {
        throw std::runtime_error(
            Helpers::BuildString("Couldn't draw line: ", SDL_GetError()));
    }
}
void Renderer::AntiAliasedLine(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                               SDL_Color color)
{
    if (aalineRGBA(m_handle, x1, y1, x2, y2, color.r, color.g, color.b,
                   color.a) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw anti-aliased line: ", SDL_GetError()));
    }
}
void Renderer::ThickLine(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                         Uint8 width, SDL_Color color)
{
    if (thickLineRGBA(m_handle, x1, y1, x2, y2, width, color.r, color.g,
                      color.b, color.a) != 0)
    {
        throw std::runtime_error(
            Helpers::BuildString("Couldn't draw thick line: ", SDL_GetError()));
    }
}
void Renderer::Circle(Sint16 x, Sint16 y, Sint16 radius, SDL_Color color)
{
    if (circleRGBA(m_handle, x, y, radius, color.r, color.g, color.b,
                   color.a) != 0)
    {
        throw std::runtime_error(
            Helpers::BuildString("Couldn't draw circle: ", SDL_GetError()));
    }
}
void Renderer::Arc(Sint16 x, Sint16 y, Sint16 radius, Sint16 startAngle,
                   Sint16 endAngle, SDL_Color color)
{
    if (arcRGBA(m_handle, x, y, radius, startAngle, endAngle, color.r, color.g,
                color.b, color.a) != 0)
    {
        throw std::runtime_error(
            Helpers::BuildString("Couldn't draw circle: ", SDL_GetError()));
    }
}
void Renderer::AntiAliasedCircle(Sint16 x, Sint16 y, Sint16 radius,
                                 SDL_Color color)
{
    if (aacircleRGBA(m_handle, x, y, radius, color.r, color.g, color.b,
                     color.a) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw anti-aliased circle: ", SDL_GetError()));
    }
}
void Renderer::FilledCircle(Sint16 x, Sint16 y, Sint16 radius, SDL_Color color)
{
    if (filledCircleRGBA(m_handle, x, y, radius, color.r, color.g, color.b,
                         color.a) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw filled circle: ", SDL_GetError()));
    }
}
void Renderer::Ellipse(Sint16 x, Sint16 y, Sint16 radiusX, Sint16 radiusY,
                       SDL_Color color)
{
    if (ellipseRGBA(m_handle, x, y, radiusX, radiusY, color.r, color.g, color.b,
                    color.a) != 0)
    {
        throw std::runtime_error(
            Helpers::BuildString("Couldn't draw ellipse: ", SDL_GetError()));
    }
}
void Renderer::AntiAliasedEllipse(Sint16 x, Sint16 y, Sint16 radiusX,
                                  Sint16 radiusY, SDL_Color color)
{
    if (aaellipseRGBA(m_handle, x, y, radiusX, radiusY, color.r, color.g,
                      color.b, color.a) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw anti-aliased ellipse: ", SDL_GetError()));
    }
}
void Renderer::FilledEllipse(Sint16 x, Sint16 y, Sint16 radiusX, Sint16 radiusY,
                             SDL_Color color)
{
    if (filledEllipseRGBA(m_handle, x, y, radiusX, radiusY, color.r, color.g,
                          color.b, color.a) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw filled ellipse: ", SDL_GetError()));
    }
}
void Renderer::Pie(Sint16 x, Sint16 y, Sint16 radius, Sint16 startAngle,
                   Sint16 endAngle, SDL_Color color)
{
    if (pieRGBA(m_handle, x, y, radius, startAngle, endAngle, color.r, color.g,
                color.b, color.a) != 0)
    {
        throw std::runtime_error(
            Helpers::BuildString("Couldn't draw pie: ", SDL_GetError()));
    }
}
void Renderer::FilledPie(Sint16 x, Sint16 y, Sint16 radius, Sint16 startAngle,
                         Sint16 endAngle, SDL_Color color)
{
    if (filledPieRGBA(m_handle, x, y, radius, startAngle, endAngle, color.r,
                      color.g, color.b, color.a) != 0)
    {
        throw std::runtime_error(
            Helpers::BuildString("Couldn't draw filled pie: ", SDL_GetError()));
    }
}
void Renderer::Trigon(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3,
                      Sint16 y3, SDL_Color color)
{
    if (trigonRGBA(m_handle, x1, y1, x2, y2, x3, y3, color.r, color.g, color.b,
                   color.a) != 0)
    {
        throw std::runtime_error(
            Helpers::BuildString("Couldn't draw trigon: ", SDL_GetError()));
    }
}
void Renderer::AntiAliasedTrigon(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                                 Sint16 x3, Sint16 y3, SDL_Color color)
{
    if (aatrigonRGBA(m_handle, x1, y1, x2, y2, x3, y3, color.r, color.g,
                     color.b, color.a) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw anti-aliased trigon: ", SDL_GetError()));
    }
}
void Renderer::FilledTrigon(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                            Sint16 x3, Sint16 y3, SDL_Color color)
{
    if (filledTrigonRGBA(m_handle, x1, y1, x2, y2, x3, y3, color.r, color.g,
                         color.b, color.a) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw filled trigon: ", SDL_GetError()));
    }
}
void Renderer::Polygon(const std::vector<Sint16> &xs,
                       const std::vector<Sint16> &ys, SDL_Color color)
{
    if (polygonRGBA(m_handle, xs.data(), ys.data(), xs.size(), color.r, color.g,
                    color.b, color.a) != 0)
    {
        throw std::runtime_error(
            Helpers::BuildString("Couldn't draw polygon: ", SDL_GetError()));
    }
}
void Renderer::AntiAliasedPolygon(const std::vector<Sint16> &xs,
                                  const std::vector<Sint16> &ys,
                                  SDL_Color color)
{
    if (aapolygonRGBA(m_handle, xs.data(), ys.data(), xs.size(), color.r,
                      color.g, color.b, color.a) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw anti-aliased polygon: ", SDL_GetError()));
    }
}
void Renderer::FilledPolygon(const std::vector<Sint16> &xs,
                             const std::vector<Sint16> &ys, SDL_Color color)
{
    if (filledPolygonRGBA(m_handle, xs.data(), ys.data(), xs.size(), color.r,
                          color.g, color.b, color.a) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw filled polygon: ", SDL_GetError()));
    }
}
void Renderer::TexturedPolygon(const std::vector<Sint16> &xs,
                               const std::vector<Sint16> &ys, Surface *texture,
                               int textureDX, int textureDY)
{
    if (texturedPolygon(m_handle, xs.data(), ys.data(), xs.size(),
                        texture->Get(), textureDX, textureDY) != 0)
    {
        throw std::runtime_error(Helpers::BuildString(
            "Couldn't draw textured polygon: ", SDL_GetError()));
    }
}
void Renderer::Bezier(const std::vector<Sint16> &xs,
                      const std::vector<Sint16> &ys, int s, SDL_Color color)
{
    if (bezierRGBA(m_handle, xs.data(), ys.data(), xs.size(), s, color.r,
                   color.g, color.b, color.a) != 0)
    {
        throw std::runtime_error(
            Helpers::BuildString("Couldn't draw Bezier: ", SDL_GetError()));
    }
}
} // namespace sdl::Gfx
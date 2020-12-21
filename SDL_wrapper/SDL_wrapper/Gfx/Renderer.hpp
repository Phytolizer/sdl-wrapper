#pragma once

#include "../Surface.hpp"
#include "../pch.h"
#include <SDL2/SDL_render.h>

namespace sdl
{
class Renderer;
}

namespace sdl::Gfx
{

class Renderer
{
  private:
    Renderer(SDL_Renderer *handle);
    SDL_Renderer *m_handle;

    friend class sdl::Renderer;

  public:
    void Pixel(Sint16 x, Sint16 y, SDL_Color color);
    void HorizontalLine(Sint16 x1, Sint16 x2, Sint16 y, SDL_Color color);
    void VerticalLine(Sint16 x, Sint16 y1, Sint16 y2, SDL_Color color);
    void Rectangle(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, SDL_Color color);
    void RoundedRectangle(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                          Sint16 radius, SDL_Color color);
    void Box(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, SDL_Color color);
    void RoundedBox(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 radius,
                    SDL_Color color);
    void Line(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, SDL_Color color);
    void AntiAliasedLine(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                         SDL_Color color);
    void ThickLine(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 width,
                   SDL_Color color);
    void Circle(Sint16 x, Sint16 y, Sint16 radius, SDL_Color color);
    void Arc(Sint16 x, Sint16 y, Sint16 radius, Sint16 startAngle,
             Sint16 endAngle, SDL_Color color);
    void AntiAliasedCircle(Sint16 x, Sint16 y, Sint16 radius, SDL_Color color);
    void FilledCircle(Sint16 x, Sint16 y, Sint16 radius, SDL_Color color);
    void Ellipse(Sint16 x, Sint16 y, Sint16 radiusX, Sint16 radiusY,
                 SDL_Color color);
    void AntiAliasedEllipse(Sint16 x, Sint16 y, Sint16 radiusX, Sint16 radiusY,
                            SDL_Color color);
    void FilledEllipse(Sint16 x, Sint16 y, Sint16 radiusX, Sint16 radiusY,
                       SDL_Color color);
    void Pie(Sint16 x, Sint16 y, Sint16 radius, Sint16 startAngle,
             Sint16 endAngle, SDL_Color color);
    void FilledPie(Sint16 x, Sint16 y, Sint16 radius, Sint16 startAngle,
                   Sint16 endAngle, SDL_Color color);
    void Trigon(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3,
                Sint16 y3, SDL_Color color);
    void AntiAliasedTrigon(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                           Sint16 x3, Sint16 y3, SDL_Color color);
    void FilledTrigon(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3,
                      Sint16 y3, SDL_Color color);
    void Polygon(const std::vector<Sint16> &xs, const std::vector<Sint16> &ys,
                 SDL_Color color);
    void AntiAliasedPolygon(const std::vector<Sint16> &xs,
                            const std::vector<Sint16> &ys, SDL_Color color);
    void FilledPolygon(const std::vector<Sint16> &xs,
                       const std::vector<Sint16> &ys, SDL_Color color);
    void TexturedPolygon(const std::vector<Sint16> &xs,
                         const std::vector<Sint16> &ys, Surface *texture,
                         int textureDX, int textureDY);
    void Bezier(const std::vector<Sint16> &xs, const std::vector<Sint16> &ys,
                int s, SDL_Color color);
};

} // namespace sdl::Gfx

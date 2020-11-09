#pragma once

#include "Primitives.hpp"
#include "Rect.hpp"
#include "pch.h"

namespace sdl
{

class Surface;
class Window;
class Texture;

constexpr auto RENDERER_DELETER = [](SDL_Renderer *handle) {
    if (handle != nullptr)
    {
        SDL_DestroyRenderer(handle);
    }
};

class Renderer
{
    std::unique_ptr<SDL_Renderer, decltype(RENDERER_DELETER)> m_handle;

  public:
    Renderer(const sdl::Window &window, int index, Uint32 flags);
    explicit Renderer(const Surface &surface);

    [[nodiscard]] SDL_Renderer *Get() const noexcept;

    void Copy(const Texture &texture, std::optional<SDL_Rect> &&srcRect,
              std::optional<SDL_Rect> &&destRect) const;
    // Set the color for future draw operations.
    void SetDrawColor(const SDL_Color &color);
    // Clear the renderer, filling its contents
    // with its current draw color.
    void Clear();
    // Push the renderer's contents to the screen.
    void Present() noexcept;

    void DrawLine(int x1, int y1, int x2, int y2);
    void DrawLine(const point &p1, const point &p2);

    void DrawLines(const std::vector<point> &vertices);

    void DrawPoint(int x, int y);
    void DrawPoint(const point &p);

    void DrawPoints(const std::vector<point> &points);

    void DrawRect(const rect &r);
    void DrawRects(const std::vector<rect> &rects);

    void FillRect(const rect &r);
    void FillRects(const std::vector<rect> &rects);

    void SetViewport(const rect &vp);

    [[nodiscard]] rect GetClipRect() const noexcept;
    [[nodiscard]] bool IsIntegerScale() const noexcept;
    [[nodiscard]] size GetLogicalSize() const noexcept;
};
} // namespace sdl
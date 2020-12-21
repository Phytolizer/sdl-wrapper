#pragma once

#include "Primitives.hpp"
#include "Rect.hpp"
#include "SDL_wrapper/Gfx/Renderer.hpp"
#include "pch.h"

namespace sdl
{
class Texture;
class RefTexture;

class Surface;
class Window;

class Renderer
{
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_handle;

  public:
    Renderer(const sdl::Window &window, int index, Uint32 flags);
    explicit Renderer(const Surface &surface);

    [[nodiscard]] SDL_Renderer *Get() const noexcept;

    void Copy(const Texture &texture, std::optional<rect> &&srcRect,
              std::optional<rect> &&destRect) const;

    void CopyEx(const Texture &texture, std::optional<rect> &&srcRect,
                std::optional<rect> &&destRect, double angle,
                std::optional<point> &&center, SDL_RendererFlip flip);
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
    [[nodiscard]] Scale GetScale() const noexcept;
    [[nodiscard]] rect GetViewport() const noexcept;
    [[nodiscard]] bool IsClipEnabled() const noexcept;
    [[nodiscard]] SDL_BlendMode GetDrawBlendMode() const;
    [[nodiscard]] SDL_Color GetDrawColor() const;
    [[nodiscard]] SDL_RendererInfo GetInfo() const;
    [[nodiscard]] size GetOutputSize() const;
    [[nodiscard]] std::optional<Texture> GetTarget() const noexcept;
    [[nodiscard]] bool TargetSupported() const noexcept;
    [[nodiscard]] Gfx::Renderer AsGfxRenderer() const noexcept;

    void SetClipRect(const rect &r);
    void SetIntegerScale(bool enable);
    void SetLogicalSize(const size &sz);
    void SetScale(const Scale &s);
    void SetDrawBlendMode(SDL_BlendMode mode);
    void SetTarget(const Texture &target);
};
} // namespace sdl
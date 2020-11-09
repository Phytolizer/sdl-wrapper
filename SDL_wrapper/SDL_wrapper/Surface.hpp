#pragma once

#include "Context.hpp"
#include "pch.h"

namespace sdl
{

class OwnedSurface;

class Surface
{
    std::unique_ptr<Surface> m_surface;

  protected:
    Surface() = default;

  public:
    explicit Surface(std::unique_ptr<Surface> &&handle);
    virtual ~Surface() = default;
    Surface(const Surface &) = delete;
    Surface(Surface &&) = default;
    Surface &operator=(const Surface &) = delete;
    Surface &operator=(Surface &&) = default;

    static Surface LoadBmp(const Context &context, std::string_view fileName);

    [[nodiscard]] virtual SDL_Surface *Get() const noexcept;
    void Blit(std::optional<SDL_Rect> srcRect, const Surface &destination,
              std::optional<SDL_Rect> destRect) const;
};
} // namespace sdl
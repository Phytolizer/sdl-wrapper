#pragma once

#include "Context.hpp"
#include "pch.h"

namespace sdl
{

class OwnedSurface;

class Surface
{
  protected:
    SDL_Surface *m_handle;

    explicit Surface(SDL_Surface *handle);

    friend class Window;

  public:
    // virtual because OwnedSurface subclasses this
    virtual ~Surface() = default;

    Surface(const Surface &) = default;

    Surface(Surface &&) = default;

    Surface &operator=(const Surface &) = default;

    Surface &operator=(Surface &&) = default;

    static OwnedSurface LoadBmp(const Context &context,
                                std::string_view fileName);

    [[nodiscard]] SDL_Surface *Get() const noexcept;

    void Blit(std::optional<SDL_Rect> srcRect, const Surface &destination,
              std::optional<SDL_Rect> destRect) const;
};
} // namespace sdl
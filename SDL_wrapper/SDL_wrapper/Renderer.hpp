#pragma once
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
};
} // namespace sdl
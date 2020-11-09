#include "Renderer.hpp"

#include "Surface.hpp"
#include "Texture.hpp"
#include "Window.hpp"

namespace sdl
{

Renderer::Renderer(const sdl::Window &window, const int index,
                   const Uint32 flags)
    : m_handle(SDL_CreateRenderer(window.Get(), index, flags))
{
    if (!m_handle)
    {
        throw std::runtime_error(Helpers::StringBuilder()
                                     .Add("Creating SDL renderer failed: ")
                                     .Add(SDL_GetError())
                                     .Build());
    }
}

SDL_Renderer *Renderer::Get() const noexcept
{
    return m_handle.get();
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::Clear()
{
    if (SDL_RenderClear(m_handle.get()) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Clearing renderer failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::Present() noexcept
{
    SDL_RenderPresent(m_handle.get());
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::DrawLine(const int x1, const int y1, const int x2, const int y2)
{
    if (SDL_RenderDrawLine(m_handle.get(), x1, y1, x2, y2) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Drawing line failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::DrawLine(const point &p1, const point &p2)
{
    if (SDL_RenderDrawLine(m_handle.get(), p1.x, p1.y, p2.x, p2.y) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Drawing line failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::DrawLines(const std::vector<point> &vertices)
{
    if (SDL_RenderDrawLines(m_handle.get(), vertices.data(),
                            static_cast<int>(vertices.size())) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Drawing lines failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::DrawPoint(const int x, const int y)
{
    if (SDL_RenderDrawPoint(m_handle.get(), x, y) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Drawing point failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::DrawPoint(const point &p)
{
    if (SDL_RenderDrawPoint(m_handle.get(), p.x, p.y) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Drawing point failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::DrawPoints(const std::vector<point> &points)
{
    if (SDL_RenderDrawPoints(m_handle.get(), points.data(),
                             static_cast<int>(points.size())) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Drawing point failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::DrawRect(const rect &r)
{
    if (SDL_RenderDrawRect(m_handle.get(), &r) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Drawing rect failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::DrawRects(const std::vector<rect> &rects)
{
    if (SDL_RenderDrawRects(m_handle.get(), rects.data(),
                            static_cast<int>(rects.size())) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Drawing rects failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::FillRect(const rect &r)
{
    if (SDL_RenderFillRect(m_handle.get(), &r) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Filling rect failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::FillRects(const std::vector<rect> &rects)
{
    if (SDL_RenderFillRects(m_handle.get(), rects.data(),
                            static_cast<int>(rects.size())) != 0)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Filling rects failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::SetViewport(const rect &vp)
{
    SDL_RenderSetViewport(m_handle.get(), &vp);
}

rect Renderer::GetClipRect() const noexcept
{
    rect r;
    SDL_RenderGetClipRect(m_handle.get(), &r);
    return r;
}

bool Renderer::IsIntegerScale() const noexcept
{
    return SDL_RenderGetIntegerScale(m_handle.get()) == SDL_TRUE;
}

size Renderer::GetLogicalSize() const noexcept
{
    size s;
    SDL_RenderGetLogicalSize(m_handle.get(), &s.x, &s.y);
    return s;
}

Renderer::Renderer(const Surface &surface)
    : m_handle(SDL_CreateSoftwareRenderer(surface.Get()))
{
    if (!m_handle)
    {
        throw std::runtime_error{Helpers::StringBuilder()
                                     .Add("Creating software renderer failed: ")
                                     .Add(SDL_GetError())
                                     .Build()};
    }
}

void Renderer::Copy(const Texture &texture, std::optional<SDL_Rect> &&srcRect,
                    std::optional<SDL_Rect> &&destRect) const
{
    SDL_Rect *s = nullptr;
    if (srcRect.has_value())
    {
        s = &*srcRect;
    }
    SDL_Rect *d = nullptr;
    if (destRect.has_value())
    {
        s = &*destRect;
    }
    if (SDL_RenderCopy(m_handle.get(), texture.Get(), s, d) != 0)
    {
        throw std::runtime_error{
            Helpers::StringBuilder()
                .Add("Copying texture to renderer failed: ")
                .Add(SDL_GetError())
                .Build()};
    }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void Renderer::SetDrawColor(const SDL_Color &color)
{
    if (SDL_SetRenderDrawColor(m_handle.get(), color.r, color.g, color.b,
                               color.a) != 0)
    {
        throw std::runtime_error{
            Helpers::StringBuilder()
                .Add("Setting renderer draw color failed: ")
                .Add(SDL_GetError())
                .Build()};
    }
}

} // namespace sdl
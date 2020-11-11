#include "LTexture.hpp"
#include "pch.h"
#include <SDL2/SDL_events.h>

constexpr auto SCREEN_WIDTH = 640;
constexpr auto SCREEN_HEIGHT = 480;

int main(int /*argc*/, char ** /*argv*/)
{
    const auto context = sdl::Context();
    const auto videoSubsystem = context.Video();
    context.SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    const auto window =
        videoSubsystem
            .CreateWindow("Lazy Foo'", SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT)
            .Shown()
            .Build();
    auto renderer = sdl::Renderer(window, -1, SDL_RENDERER_ACCELERATED);
    renderer.SetDrawColor({0xFF, 0xFF, 0xFF, 0xFF});

    const auto imageContext = sdl::Image::Context(sdl::Image::InitFlag::png);
    auto modulatedTexture = LTexture{renderer, imageContext.Load("colors.png")};
    auto c = SDL_Color{0xFF, 0xFF, 0xFF};

    auto run = true;
    while (run)
    {
        std::optional<SDL_Event> e;
        while ((e = context.PollEvent()).has_value())
        {
            if (e->type == SDL_QUIT)
            {
                run = false;
            }
            else if (e->type == SDL_KEYDOWN)
            {
                switch (e->key.keysym.sym)
                {
                case SDLK_q:
                    c.r += 32;
                    break;
                case SDLK_w:
                    c.g += 32;
                    break;
                case SDLK_e:
                    c.b += 32;
                    break;
                case SDLK_a:
                    c.r -= 32;
                    break;
                case SDLK_s:
                    c.g -= 32;
                    break;
                case SDLK_d:
                    c.b -= 32;
                    break;
                }
            }
        }

        renderer.SetDrawColor({0xFF, 0xFF, 0xFF, 0xFF});
        renderer.Clear();

        modulatedTexture.SetColor(c);
        modulatedTexture.RenderTo(renderer, {0, 0}, {});

        renderer.Present();
    }
    return 0;
}

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

    const auto imageContext = sdl::Image::Context(sdl::Image::InitFlag::png |
                                                  sdl::Image::InitFlag::jpg);
    auto modulatedTexture =
        LTexture{renderer, imageContext.Load("fadeout.png")};
    modulatedTexture.SetBlendMode(sdl::BlendMode::blend);
    auto backgroundTexture =
        LTexture{renderer, imageContext.Load("fadein.png")};
    Uint8 a = 255;

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
                case SDLK_w:
                    if (a + 32 > 255)
                    {
                        a = 255;
                    }
                    else
                    {
                        a += 32;
                    }
                    break;
                case SDLK_s:
                    if (a - 32 < 0)
                    {
                        a = 0;
                    }
                    else
                    {
                        a -= 32;
                    }
                    break;
                }
            }
        }

        renderer.SetDrawColor({0xFF, 0xFF, 0xFF, 0xFF});
        renderer.Clear();

        backgroundTexture.RenderTo(renderer, {0, 0}, {});

        modulatedTexture.SetAlphaMod(a);
        modulatedTexture.RenderTo(renderer, {0, 0}, {});

        renderer.Present();
    }
    return 0;
}

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
        }

        renderer.SetDrawColor({0xFF, 0xFF, 0xFF, 0xFF});
        renderer.Clear();
        renderer.SetDrawColor({0xFF, 0x00, 0x00, 0xFF});
        renderer.FillRect({SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4,
                           SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2});
        renderer.SetDrawColor({0x00, 0xFF, 0x00, 0xFF});
        renderer.DrawRect({SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6,
                           SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3});
        renderer.SetDrawColor({0x00, 0x00, 0xFF, 0xFF});
        renderer.DrawLine(0, SCREEN_HEIGHT / 2, SCREEN_WIDTH,
                          SCREEN_HEIGHT / 2);
        renderer.SetDrawColor({0xFF, 0xFF, 0x00, 0xFF});
        for (auto i = 0; i < SCREEN_HEIGHT; i += 4)
        {
            renderer.DrawPoint({SCREEN_WIDTH / 2, i});
        }
        renderer.Present();
    }
    return 0;
}

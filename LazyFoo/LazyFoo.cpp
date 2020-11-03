#include "pch.h"

constexpr auto SCREEN_WIDTH = 640;
constexpr auto SCREEN_HEIGHT = 480;

int main(int /*argc*/, char ** /*argv*/)
{
    const auto context = sdl::Context();
    const auto videoSubsystem = sdl::VideoSubsystem(context);
    context.SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    const auto window = sdl::Window::Builder().Shown().Build(
        videoSubsystem, "Lazy Foo'", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT);
    auto renderer = sdl::Renderer(window, -1, SDL_RENDERER_ACCELERATED);

    auto run = true;
    while (run)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                run = false;
            }
        }

        renderer.SetDrawColor({0, 0, 0, 1});
        renderer.Clear();
        renderer.Present();
    }
    return 0;
}

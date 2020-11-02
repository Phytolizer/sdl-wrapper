#include "pch.h"

enum class key_press
{
    other,
    up,
    down,
    left,
    right
};

std::unordered_map<key_press, sdl::Surface> LoadMedia(
    const sdl::Context &context)
{
    auto out = std::unordered_map<key_press, sdl::Surface>{};

    try
    {
        out.emplace(key_press::other,
                    sdl::Surface::LoadBmp(context, "04_key_presses/press.bmp"));
        out.emplace(key_press::up,
                    sdl::Surface::LoadBmp(context, "04_key_presses/up.bmp"));
        out.emplace(key_press::down,
                    sdl::Surface::LoadBmp(context, "04_key_presses/down.bmp"));
        out.emplace(key_press::left,
                    sdl::Surface::LoadBmp(context, "04_key_presses/left.bmp"));
        out.emplace(key_press::right,
                    sdl::Surface::LoadBmp(context, "04_key_presses/right.bmp"));
    }
    catch (std::runtime_error &e)
    {
        std::cerr << "Failed loading required assets: " << e.what() << "\n";
        throw;
    }

    return out;
}

int main(int argc, char **argv)
{
    const auto context = sdl::Context();
    const auto video_subsystem = sdl::VideoSubsystem(context);
    const auto window = sdl::Window::Builder().Shown().Maximized().Build(
        video_subsystem, "Lazy Foo'", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 800, 600);
    const auto screen_surface = window.GetSurface();
    auto key_press_surfaces = LoadMedia(context);
    auto current_surface = key_press::other;

    bool run = true;
    while (run)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                run = false;
            }
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_UP:
                    current_surface = (key_press::up);
                    break;
                case SDLK_DOWN:
                    current_surface = (key_press::down);
                    break;
                case SDLK_LEFT:
                    current_surface = (key_press::left);
                    break;
                case SDLK_RIGHT:
                    current_surface = (key_press::right);
                    break;
                default:
                    current_surface = (key_press::other);
                }
            }
        }

        try
        {
            key_press_surfaces.at(current_surface).Blit({}, screen_surface, {});
        }
        catch (std::runtime_error &e)
        {
            std::cerr << e.what() << "\n";
            throw;
        }
        window.UpdateSurface();
    }
    return 0;
}

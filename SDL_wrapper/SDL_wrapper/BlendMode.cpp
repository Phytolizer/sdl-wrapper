#include "BlendMode.hpp"

sdl::BlendMode sdl::BlendModeFromSdl(const SDL_BlendMode mode)
{
    switch (mode)
    {
    case SDL_BLENDMODE_NONE:
        return sdl::BlendMode::none;
    case SDL_BLENDMODE_BLEND:
        return sdl::BlendMode::blend;
    case SDL_BLENDMODE_ADD:
        return sdl::BlendMode::add;
    case SDL_BLENDMODE_MOD:
        return sdl::BlendMode::mod;
    case SDL_BLENDMODE_MUL:
        return sdl::BlendMode::mul;
    case SDL_BLENDMODE_INVALID:
        return sdl::BlendMode::invalid;
    }
    throw std::runtime_error{Helpers::StringBuilder()
                                 .Add("Received impossible BlendMode value of ")
                                 .Add(mode)
                                 .Build()};
}
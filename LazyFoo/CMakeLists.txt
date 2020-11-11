
cmake_minimum_required (VERSION 3.16)

file(GLOB SOURCES CONFIGURE_DEPENDS
        "*.cpp"
        "*.hpp")

add_executable(LazyFoo ${SOURCES})
target_link_libraries(LazyFoo SDL_wrapper Helpers)
target_precompile_headers(LazyFoo PRIVATE "pch.h")


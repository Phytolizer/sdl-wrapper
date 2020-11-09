
cmake_minimum_required (VERSION 3.16)

add_executable(LazyFoo "LazyFoo.cpp" "pch.cpp")
target_link_libraries(LazyFoo SDL_wrapper Helpers)
target_precompile_headers(LazyFoo PRIVATE "pch.h")


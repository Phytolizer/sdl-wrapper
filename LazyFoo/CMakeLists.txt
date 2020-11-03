
cmake_minimum_required (VERSION 3.16)

add_executable(LazyFoo "LazyFoo.cpp" "pch.cpp")
target_link_libraries(LazyFoo ${CONAN_LIBS} SDL_wrapper Helpers)
target_include_directories(LazyFoo PRIVATE ${TOPDIR}/SDL_wrapper ${TOPDIR}/Helpers)
target_precompile_headers(LazyFoo PRIVATE "pch.h")


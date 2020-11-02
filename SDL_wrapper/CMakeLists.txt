# CMakeList.txt : CMake project for SDL_wrapper, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.16)

# Add source to this project's executable.
file(GLOB_RECURSE SOURCES "*.cpp")
add_library (SDL_wrapper STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS} Helpers)
target_include_directories(${PROJECT_NAME} PRIVATE ${TOPDIR}/Helpers)
target_precompile_headers(${PROJECT_NAME} PRIVATE "SDL_wrapper/pch.h")

# TODO: Add tests and install targets if needed.

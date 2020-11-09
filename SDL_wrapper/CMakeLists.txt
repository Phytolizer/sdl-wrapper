# CMakeList.txt : CMake project for SDL_wrapper, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.16)

# Add source to this project's executable.
file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.hpp")
add_library (SDL_wrapper STATIC ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} PUBLIC Helpers SDL2 SDL2main SDL2_image)
target_link_directories(${PROJECT_NAME} PUBLIC
    "C:/dev/libs/SDL2_image/lib/x64"
    "C:/dev/libs/SDL2/lib/x64"
)
target_include_directories(${PROJECT_NAME} PUBLIC .
		"C:\\dev\\libs\\SDL2\\include"
		"C:\\dev\\libs\\SDL2_image\\include"
)
target_precompile_headers(${PROJECT_NAME} PRIVATE "SDL_wrapper/pch.h")

# TODO: Add tests and install targets if needed.

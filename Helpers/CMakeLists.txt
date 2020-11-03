
cmake_minimum_required (VERSION 3.16)

file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.hpp")
add_library(Helpers STATIC ${SOURCES} ${HEADERS})
target_link_libraries(Helpers ${CONAN_LIBS})
target_precompile_headers(Helpers PRIVATE "Helpers/pch.h")

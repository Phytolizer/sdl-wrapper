
cmake_minimum_required(VERSION 3.16)

add_library(Helpers STATIC "Helpers.hpp" "Helpers/pch.h" "Helpers/pch.cpp" "Helpers/OutputStream.hpp" "Helpers/OutputStream.cpp" "Helpers/StringBuilder.hpp" "Helpers/StringBuilder.cpp")
if (WIN32)
    target_link_libraries(Helpers ${CONAN_LIBS})
endif ()
target_precompile_headers(Helpers PRIVATE "Helpers/pch.h")

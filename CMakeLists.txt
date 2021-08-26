cmake_minimum_required(VERSION 3.16)
project(snowy)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES
        src/**/**/**/*.h
        src/**/**/**/*.cpp
        src/**/**/*.h
        src/**/**/*.cpp
        src/**/*.h
        src/**/*.cpp
        src/*.h
        src/*.cpp
#        dependencies/stb/*.cpp
#        dependencies/stb/*.h
        )

add_executable(snowy ${SOURCES})
add_compile_definitions(SNOW_ENABLE_ASSERTS=TRUE)
target_precompile_headers(snowy PRIVATE src/pch.h)

target_include_directories(snowy PUBLIC src)
target_include_directories(snowy PUBLIC dependencies/glm/glm)
target_include_directories(snowy PUBLIC dependencies/stb)
target_include_directories(snowy PUBLIC dependencies/entt)

# spdlog
add_subdirectory(dependencies/spdlog)
target_include_directories(snowy PUBLIC dependencies/spdlog/include)

# GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory(dependencies/glfw)
target_include_directories(snowy PRIVATE dependencies/glfw/GLFW/include)
target_link_libraries(snowy "glfw" "${GLFW_LIBRARIES}")
target_compile_definitions(snowy PRIVATE "GLFW_INCLUDE_NONE")

# imgui
add_subdirectory(dependencies/imgui)
target_include_directories(snowy PUBLIC dependencies/imgui)
target_link_libraries(snowy imgui)

# glad
add_library(glad dependencies/glad/src/glad.c)
target_include_directories(glad PRIVATE dependencies/glad/include)
target_include_directories(snowy PRIVATE dependencies/glad/include)
target_link_libraries(snowy glad "${CMAKE_DL_LIBS}")
#target_compile_options(glad PRIVATE -fPIC)
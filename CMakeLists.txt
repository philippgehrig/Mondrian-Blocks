cmake_minimum_required(VERSION 3.22)

project(CPP-Exam CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

set(RAYLIB_VERSION 4.5.0)
set(GOOGLETEST_VERSION v1.13.0)

set(Headers
        src/Game/Game.hpp
        src/Block/Block.hpp
        src/Board/Board.hpp
        src/GUI/GUI.hpp
        src/Constants.hpp
        src/Solver/Solver.hpp
)

set(Sources
        src/Board/Board.cpp
        src/Game/Game.cpp
        src/GUI/GUI.cpp
        src/Solver/Solver.cpp
)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/${GOOGLETEST_VERSION}.tar.gz
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Our Project
add_executable(${PROJECT_NAME} ${Sources} ${Headers}
        src/main.cpp
        test/test.cpp
)

add_library(${PROJECT_NAME}_lib STATIC ${Sources} ${Headers})

target_link_libraries(${PROJECT_NAME}_lib raylib gtest)

target_link_libraries(${PROJECT_NAME} raylib gtest)

include_directories(${raylib_BUILD_DIR}/raylib/include)


# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
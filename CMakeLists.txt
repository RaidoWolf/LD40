cmake_minimum_required (VERSION 3.1)

# build type selection
if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif ()

# notify of the build type in use
message (STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

# project
project (LD40)
set (LD40_VERSION_MAJOR 0)
set (LD40_VERSION_MINOR 0)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")
set (CMAKE_CXX_FLAGS_DEBUG "-g")
set (CMAKE_CXX_FLAGS_RELEASE "-O3")
configure_file (
    "${PROJECT_SOURCE_DIR}/src/config.h.in"
    "${PROJECT_BINARY_DIR}/src/config.h"
)
include_directories ("${PROJECT_BINARY_DIR}")

# sources list
list (APPEND SOURCES

    # game code
    src/class/AssetStore/AssetStore.hpp
    src/class/AssetStore/AssetStore.cpp
    src/class/Controller/Controller.hpp
    src/class/Controller/Controller.cpp
    src/class/GameLoop/GameLoop.hpp
    src/class/GameLoop/GameLoop.cpp
    src/class/GameState/GameState.hpp
    src/class/GameState/GameState.cpp
    src/class/GameStateManager/GameStateManager.hpp
    src/class/GameStateManager/GameStateManager.cpp
    src/class/GameStateStore/GameStateStore.hpp
    src/class/GameStateStore/GameStateStore.cpp
    src/class/Keybinding/Keybinding.hpp
    src/class/Keybinding/Keybinding.cpp
    src/class/LoadingState/LoadingState.hpp
    src/class/LoadingState/LoadingState.cpp
    src/class/Log/Log.hpp
    src/class/Log/Log.cpp
    src/class/LoopKeybinding/LoopKeybinding.hpp
    src/class/LoopKeybinding/LoopKeybinding.cpp
    src/class/Window/Window.hpp
    src/class/Window/Window.cpp
    src/enum/LogLevel/LogLevel.hpp

    # entry point
    src/main.cpp

)

# executable output
set (EXECUTABLE_NAME "LD40")
add_executable (${EXECUTABLE_NAME} ${SOURCES})

# cmake modules
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# dependencies
find_package (SFML 2 REQUIRED audio graphics window system)
if (SFML_FOUND)
    include_directories (${SFML_INCLUDE_DIR})
    target_link_libraries (${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

# installation
install (TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# packaging
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set (CPACK_PACKAGE_VESRION_MAJOR "${LD40_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${LD40_VERSION_MINOR}")
include (CPack)

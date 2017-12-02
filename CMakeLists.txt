cmake_minimum_required (VERSION 3.1)

# build type selection
if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif ()

# project
project (LD40)
set (LD40_VERSION_MAJOR 0)
set (LD40_VERSION_MINOR 0)
set (CMAKE_CXX_STANDARD 14)
configure_file (
    "${PROJECT_SOURCE_DIR}/src/config.h.in"
    "${PROJECT_BINARY_DIR}/src/config.h"
)
include_directories ("${PROJECT_BINARY_DIR}")

# sources list
list (APPEND SOURCES

    # game code
    src/class/Log/Log.hpp
    src/class/Log/Log.cpp
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
find_package (SFML 2 REQUIRED network audio graphics window system)
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

cmake_minimum_required(VERSION 3.28)
project(raylib-game VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Setting up libs here
set(PKG_LIBRARIES
    raylib
)

set(OTHER_LIBRARIES
    cunit
)

# Specific target CMAKE configuration
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror -g -DDEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options(-DRELEASE)
    message("RELEASE STILL HAVE A CMAKE CONFIG TODO")
endif()

# Checking if PKG_LIBRARIES exist within the system
foreach(LIB ${PKG_LIBRARIES})
    find_package(${LIB} REQUIRED)
endforeach()

# Fetch source files
file(GLOB SOURCE_FILES src/*.c)

# Compilation settings and lib linking
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${PKG_LIBRARIES} ${OTHER_LIBRARIES})

# Installation of the project
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_BINARY_DIR}/bin)
install(DIRECTORY assets DESTINATION ${CMAKE_BINARY_DIR}/bin)



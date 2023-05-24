cmake_minimum_required (VERSION 3.12)
project (uart)

# Initialize CMake library for KasperskyOS SDK.
include (platform)
initialize_platform (FORCE_STATIC)

# This command finds all components of the uart package.
find_package (uart REQUIRED)
include_directories (${uart_INCLUDE})

add_subdirectory (client)
add_subdirectory (einit)

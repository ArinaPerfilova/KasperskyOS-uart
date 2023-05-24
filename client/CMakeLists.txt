project (client)

# Tools for using NK parser.
include (platform/nk)

nk_build_edl_files (client_edl_files NK_MODULE "client" EDL "${CMAKE_SOURCE_DIR}/resources/edl/Client.edl")

add_executable (client_qemu "uart.c")
add_dependencies (client_qemu client_edl_files)
set_target_compiler_flags_default (client_qemu "STANDARD_GNU_C99:YES" "STRICT_WARNINGS:NO")
target_compile_definitions (client_qemu PRIVATE "-DPORT_NAME=\"${PORT_QEMU}\"")
target_link_libraries (client_qemu ${uart_CLIENT_LIB})
#set_target_properties (client_qemu PROPERTIES LINK_FLAGS "-no-pie -Ttext 0x00800000")

add_executable (client_hw "uart.c")
add_dependencies (client_hw client_edl_files)
set_target_compiler_flags_default (client_hw "STANDARD_GNU_C99:YES" "STRICT_WARNINGS:NO")
target_compile_definitions (client_hw PRIVATE "-DPORT_NAME=\"${PORT_HW}\"")
target_link_libraries (client_hw ${uart_CLIENT_LIB})
#set_target_properties (client_hw PROPERTIES LINK_FLAGS "-no-pie -Ttext 0x00800000")

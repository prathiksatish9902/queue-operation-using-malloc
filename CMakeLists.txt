cmake_minimum_required(VERSION 3.16)

project(queue_operation_using_malloc LANGUAGES C)

add_executable(queue_operation_using_malloc main.c)

include(GNUInstallDirs)
install(TARGETS queue_operation_using_malloc
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

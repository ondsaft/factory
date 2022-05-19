cmake_minimum_required(VERSION 3.10)

project(machines VERSION 1.0)

add_library(machines prod_data.c)

target_include_directories(machines INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(machines PUBLIC
    "${PROJECT_BINARY_DIR}"
    )

install(TARGETS machines DESTINATION lib)
install(FILES prod_data.h DESTINATION include)
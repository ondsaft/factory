cmake_minimum_required(VERSION 3.10)

project(factory VERSION 1.0)

option(USE_MYMACHINES "Use factory provided machines implementation" ON)

configure_file(factory_config.h.in factory_config.h)

add_subdirectory(apps)
add_subdirectory(machines)

#add_executable(factory factory.c)

#target_link_libraries(factory PUBLIC machines)

target_include_directories(factory PUBLIC
    "${PROJECT_BINARY_DIR}"
    )

install(TARGETS factory DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/factory_config.h" DESTINATION include)
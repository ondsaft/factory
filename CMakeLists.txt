cmake_minimum_required(VERSION 3.10)

project(factory VERSION 1.0)

option(USE_MYMACHINES "Use factory provided machines implementation" ON)

configure_file(factory_config.h.in factory_config.h)

add_subdirectory(apps)

# uncomment below to include machines library in factory
#add_subdirectory(machines)

target_include_directories(factory PUBLIC
    "${PROJECT_BINARY_DIR}"
    )

install(TARGETS factory DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/factory_config.h" DESTINATION include)
add_library(machines prod_data.c)

target_include_directories(machines INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS machines DESTINATION lib)
install(FILES prod_data.h DESTINATION include)
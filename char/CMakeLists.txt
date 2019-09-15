project(char_snake)

aux_source_directory(src char_snake_src)

add_executable(char_snake ${char_snake_src} ${core_src})

target_include_directories(char_snake PRIVATE include)
target_include_directories(char_snake PUBLIC ${headers})

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_link_libraries(char_snake PRIVATE pthread)
endif()

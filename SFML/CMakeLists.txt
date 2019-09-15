project(SFML_snake)

aux_source_directory(src SFML_snake_src)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(SFML_snake ${SFML_snake_src} ${core_src})

target_include_directories(SFML_snake PRIVATE include)
target_include_directories(SFML_snake PUBLIC ${headers})

target_link_libraries(SFML_snake sfml-graphics sfml-audio)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_link_libraries(SFML_snake pthread)
endif()

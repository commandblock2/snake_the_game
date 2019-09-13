project(char_snake)

aux_source_directory(src char_snake_src)
include_directories(./include)

add_executable(char_snake ${char_snake_src} ${core_src})

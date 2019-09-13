cmake_minimum_required(VERSION 3.14)

if(MSVC)
	add_compile_options("/std:c++17")
else()
	set(CMAKE_CXX_STANDARD_REQUIRED 17)
endif()

option(SFML_snake "build SFML snake" off)
option(OPENGL_snake "build OPENGL snake" off)
option(Qt_snake "build Qt snake" off)
option(char_snake "build char snake" on)


aux_source_directory(${PROJECT_SOURCE_DIR}/core/src core_src)
set(headers ${PROJECT_SOURCE_DIR}/core/include)


if(SFML_snake)
endif()

if(OPENGL_snake)
endif()

if(Qt_snake)
endif()

if(char_snake)
	message("char snake")
	add_subdirectory(./char)
endif()
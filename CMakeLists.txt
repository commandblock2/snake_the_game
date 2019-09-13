cmake_minimum_required(VERSION 3.14)

option(SFML_snake "build SFML snake" off)
option(OPENGL_snake "build OPENGL snake" off)
option(Qt_snake "build Qt snake" off)
option(char_snake "build char snake" on)


add_subdirectory(./core)


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
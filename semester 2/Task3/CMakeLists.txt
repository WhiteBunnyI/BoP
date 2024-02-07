cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME Custom_String)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


include_directories("inc/")

add_executable("${PROJECT_NAME}" main.cpp
		inc/cString.hpp src/cString.cpp)

set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT "${PROJECT_NAME}")

#file(COPY "assets/" DESTINATION "/")
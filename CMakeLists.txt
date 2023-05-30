cmake_minimum_required(VERSION 3.25)
project(AcFly)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_DIRECTORY build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
add_subdirectory(lib)
add_subdirectory(GoogleTest)
add_subdirectory(src)







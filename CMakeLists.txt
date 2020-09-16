cmake_minimum_required(VERSION 3.13)
project(projet_ips1)

set (CMAKE_CXX_STANDARD 11)

set(COMPILE_OPTIONS PRIVATE -v -flto=full -Wall -Wextra  -O3)

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})
add_executable(main src/hermite.cpp  src/main.cpp)
target_link_libraries(main ${ARMADILLO_LIBRARIES})
target_compile_options(main ${COMPILE_OPTIONS})



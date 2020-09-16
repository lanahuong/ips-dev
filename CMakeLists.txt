cmake_minimum_required(VERSION 3.13)
project(projet_ips1)

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})
add_executable(main src/hermite.cpp  src/main.cpp)
target_link_libraries(main ${ARMADILLO_LIBRARIES})

set(CMAKE_CXX_STANDARD 14)


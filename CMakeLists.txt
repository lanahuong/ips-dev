cmake_minimum_required(VERSION 3.13)
project(projet_ips1)
set (CMAKE_CXX_STANDARD 11)
set(COMPILE_OPTIONS PRIVATE -v -flto=full -Wall -Wextra  -O3)

#Armadillo
find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

#GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#MAIN
add_executable(main src/hermite.cpp  src/main.cpp src/solverschrodinger.cpp src/derivator.cpp)
target_link_libraries(main ${ARMADILLO_LIBRARIES})
target_compile_options(main ${COMPILE_OPTIONS})

#TESTS
#add_executable(tests tests/hermite_tests.cpp src/hermite.cpp)
#target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
#target_link_libraries(tests ${ARMADILLO_LIBRARIES})
#target_compile_options(tests ${COMPILE_OPTIONS})





cmake_minimum_required(VERSION 3.13)
project(projet_ips1)
set(CMAKE_CXX_STANDARD 11)
set(COMPILE_OPTIONS PRIVATE -Wall -Wextra) #)-Werror -pedantic -ansi -Wshadow -Wdouble-promotion -Wundef -fno-common -Wconversion -Wunused-parameter)

#Armadillo
find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

#GoogleTest

include_directories(gtest/googletest/include)

#MAIN
add_executable(main src/Hermite.cpp src/main.cpp src/SolverSchrodinger.cpp src/Derivator.cpp src/OrthogonalityChecker.cpp src/Saver.cpp)
target_link_libraries(main ${ARMADILLO_LIBRARIES})
target_compile_options(main ${COMPILE_OPTIONS})

#TESTS
add_executable(tests src/Hermite.cpp src/SolverSchrodinger.cpp src/Derivator.cpp tests/testsHermite.cpp tests/testsSolverSchrodinger.cpp tests/testsOrthogonalityChecker.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
target_link_libraries(tests ${ARMADILLO_LIBRARIES})
target_compile_options(tests ${COMPILE_OPTIONS})





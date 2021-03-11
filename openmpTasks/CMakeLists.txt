cmake_minimum_required(VERSION 3.17)
project(openmpTasks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(CMAKE_CXX_STANDARD 17)

add_executable(openmpTasks main.cpp src/openmpProblems/omp_tasks.h
        src/openmpProblems/t1_hello_world.cpp src/openmpProblems/t2_if.cpp src/openmpProblems/t3_private.cpp
        src/openmpProblems/t4_minmax.cpp src/openmpProblems/t5_section.cpp src/openmpProblems/t6_reduction.cpp
        src/openmpProblems/t7_schedule.cpp src/openmpProblems/t8_schedule.cpp src/openmpProblems/t9_sc_matrix.cpp
        src/openmpProblems/t10_matrix_maxmin.cpp src/openmpProblems/t11_atomic.cpp src/openmpProblems/t12_div.cpp)
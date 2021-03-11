cmake_minimum_required(VERSION 3.17)
project(mpiProblem)

find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

set(CMAKE_CXX_STANDARD 17)

add_executable(mpiProblem main.cpp problems/t1_hw.cpp problems/mpi_tasks.h problems/t2_array_max.cpp)
target_link_libraries(mpiProblem ${MPI_LIBRARIES})

if (MPI_COMPILE_FLAGS)
    set_target_properties(main PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif ()

if (MPI_LINK_FLAGS)
    set_target_properties(main PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif ()

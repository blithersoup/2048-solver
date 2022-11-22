file(GLOB_RECURSE SRC_CPP "*.cpp")
file(GLOB_RECURSE SRC_HPP "*.hpp")

add_executable(2048_solver
    ${SRC_CPP}
    ${SRC_HPP}
)
set(CMAKE_BUILD_TYPE Debug)
file(GLOB_RECURSE SRC_CPP "*.cpp")
file(GLOB_RECURSE SRC_HPP "*.hpp")


add_library(2048_solver SHARED
    ${SRC_CPP}
    ${SRC_HPP}
)
cmake_minimum_required( VERSION 3.5 )
project( 2048_solver VERSION 0.0.1 LANGUAGES CXX )
file(GLOB_RECURSE 2048_src 
    DEPENDS 
    "*.cpp"
    "*.hpp"
)
add_library(2048_solver SHARED 
    ${2048_src}
)

set_target_properties(2048_solver PROPERTIES LINKER_LANGUAGE CXX)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/2048_solver_config_versions.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)
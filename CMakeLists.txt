cmake_minimum_required( VERSION 3.5 )
project( 2048_solver VERSION 0.0.1 LANGUAGES CXX )

add_subdirectory(src)

set_target_properties(2048_solver PROPERTIES LINKER_LANGUAGE CXX)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/2048_solver_config_versions.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)
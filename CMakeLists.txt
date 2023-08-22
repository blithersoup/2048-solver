cmake_minimum_required(VERSION 3.12)

project(solver_cmake_build LANGUAGES CXX VERSION 0.1)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/2048_solver_config_versions.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

execute_process(COMMAND cling-config --cmake OUTPUT_VARIABLE CPPYY_MODULE_PATH OUTPUT_STRIP_TRAILING_WHITESPACE)
list(INSERT CMAKE_MODULE_PATH 0 ${CPPYY_MODULE_PATH})
find_package(Cppyy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fomit-frame-pointer -march=native -flto -funroll-loops")

if(NOT CMAKE_BUILD_TYPE) 
    set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(src)

add_library(cpp SHARED ${SRC_CPP})

set_target_properties(cpp PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(cpp PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1)
# set_target_properties(cpp PROPERTIES PUBLIC_HEADER ${SRC_HPP})

target_include_directories(cpp PUBLIC ${CMAKE_SOURCE_DIR}/src/)

cppyy_add_bindings(
   "solvera"
   "${PROJECT_VERSION}"
   "Grady Arnold" 
   "gradyarnold11@gmail.com"
   URL ${PROJECT_HOMEPAGE_URL}
   LICENSE "APACHE"
   LANGUAGE_STANDARD "17"
   INCLUDE_DIRS   ${CMAKE_SOURCE_DIR}/src/cpp
   H_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
   H_FILES ${SRC_HPP}
   LINK_LIBRARIES cpp
)

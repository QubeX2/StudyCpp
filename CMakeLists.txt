cmake_minimum_required(VERSION 3.0.0)
project(StudyCpp VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)

file(GLOB src_files "src/*.cpp")

foreach(src_file IN LISTS src_files)
    get_filename_component(target "${src_file}" NAME_WE)
    add_executable("${target}" "${src_file}")
endforeach()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

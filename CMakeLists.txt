cmake_minimum_required(VERSION 3.0.0)
project(StudyCpp VERSION 0.1.0)

# add_compile_options(-v)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(CMAKE_VERBOSE_MAKEFILE ON)


if(CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
    include_directories("/usr/local/Cellar/fmt/8.1.1_1/include")
endif()

set(
   CMAKE_CXX_FLAGS
   "${CMAKE_CXX_FLAGS} -std=c++20 -O0 -W -Wall -Wextra -pedantic"
)

file(GLOB src_files "src/*.cpp")

foreach(src_file IN LISTS src_files)
    get_filename_component(target "${src_file}" NAME_WE)
    add_executable("${target}" "${src_file}")
    if(CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
        target_compile_options("${target}" PRIVATE -stdlib=libc++) 
    endif()
endforeach()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

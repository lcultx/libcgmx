## Project
cmake_minimum_required(VERSION 3.1)
project(cgmx)

# Library setup
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.*)

# Defaults
set(CGMX_TESTS TRUE CACHE BOOL "Build and run tests")

# Platform specific
if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
endif()
if(APPLE)
  if("${CMAKE_OSX_ARCHITECTURES}" EQUAL "")
    set(CMAKE_OSX_ARCHITECTURES "x86_64")
  endif()
endif()

# Build library (dynamic)
add_library(cgmx STATIC ${SOURCES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/)
set_target_properties(cgmx PROPERTIES OUTPUT_NAME cgmx)
set_target_properties(cgmx PROPERTIES BUILD_WITH_INSTALL_RPATH 1 INSTALL_NAME_DIR "@rpath")

# C++11 please
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(NOT WIN32)
  if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  endif()
endif()

# Install rules
if(NOT INSTALL_DIR)
  set(INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/release)
endif()
install(TARGETS cgmx DESTINATION "${INSTALL_DIR}")

# Handle tests
if(CGMX_TESTS)
  file(GLOB_RECURSE TESTS ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.*)
  enable_testing()
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests)
  foreach(TEST ${TESTS})
    get_filename_component(TEST_NAME ${TEST} NAME_WE)
    set(TEST_NAME "${TEST_NAME}")
    add_executable(${TEST_NAME} ${TEST})
    set_target_properties(${TEST_NAME} PROPERTIES OUTPUT_NAME tests/${TEST_NAME})
    target_link_libraries(${TEST_NAME} cgmx)
    add_test(${TEST_NAME} ${CMAKE_CURRENT_BINARY_DIR}/tests/${TEST_NAME})
  endforeach(TEST)
endif()

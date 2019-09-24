cmake_minimum_required (VERSION 3.15.3)
project (Raytracer)

set(CMAKE_CXX_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")     
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast -flto -march=native -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -pedantic -fsanitize=address --coverage")
set(CMAKE_CXX_FLAGS_TEST "${CMAKE_CXX_FLAGS_TEST} -g -pedantic -fsanitize=address -D_TESTS --coverage")

set(SHARED_INCLUDE_DIR libs)

add_library(tuple OBJECT)
target_sources(tuple
    PRIVATE "src/tuple/tuple.cc"
    PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/src/tuple/tuple.hh"
)
target_compile_options(tuple PRIVATE -Wall -Wextra -Werror)
target_link_libraries(tuple PUBLIC "")
target_include_directories(tuple PUBLIC ${SHARED_INCLUDE_DIR} src/utils)

add_library(vector OBJECT)
target_sources(vector
    PRIVATE "src/vector/vector.cc"
    PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/src/vector/vector.hh"
)
target_compile_options(vector PRIVATE -Wall -Wextra -Werror)
target_link_libraries(vector PUBLIC "")
target_include_directories(vector PUBLIC ${SHARED_INCLUDE_DIR} src/tuple)

add_library(point OBJECT)
target_sources(point
    PRIVATE "src/point/point.cc"
    PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/src/point/point.hh"
)
target_compile_options(point PRIVATE -Wall -Wextra -Werror)
target_link_libraries(point PUBLIC "")
target_include_directories(point PUBLIC ${SHARED_INCLUDE_DIR} src/tuple)

add_library(test OBJECT)
target_sources(test
    PRIVATE "tests/test.cc"
)
target_compile_options(test PRIVATE -I$(CATCH_SINGLE_INCLUDE) -Wall -Wextra -Werror)
target_include_directories(test PUBLIC ${SHARED_INCLUDE_DIR})

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Test")
    add_executable(Tests)
    target_link_libraries(Tests PRIVATE tuple vector point test)
else()
    add_executable(Raytracer)
    target_link_libraries(Raytracer PRIVATE tuple vector point)
endif()
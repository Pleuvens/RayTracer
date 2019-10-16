cmake_minimum_required (VERSION 3.15.3)
project (Raytracer)

set(CMAKE_CXX_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")     
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast -flto -march=native -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -pedantic -fsanitize=address --coverage")
set(CMAKE_CXX_FLAGS_TESTS "${CMAKE_CXX_FLAGS_TEST} -g -pedantic -fsanitize=address -D_TESTS --coverage")

set(SHARED_INCLUDE_DIR libs src/utils)

add_library(op_overloading OBJECT)
target_sources(op_overloading
    PRIVATE "src/utils/op_overloading.cc"
    PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/src/utils/op_overloading.hh"
)
target_compile_options(op_overloading PRIVATE -Wall -Wextra -Werror)
target_link_libraries(op_overloading PUBLIC "")
target_include_directories(op_overloading PUBLIC ${SHARED_INCLUDE_DIR})

add_library(tuple OBJECT)
target_sources(tuple
    PRIVATE "src/tuple/tuple.cc"
    PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/src/tuple/tuple.hh"
)
target_compile_options(tuple PRIVATE -Wall -Wextra -Werror)
target_link_libraries(tuple PUBLIC "")
target_include_directories(tuple PUBLIC ${SHARED_INCLUDE_DIR})

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
target_include_directories(point PUBLIC ${SHARED_INCLUDE_DIR} src/tuple src/vector)

add_library(color OBJECT)
target_sources(color
    PRIVATE "src/color/color.cc"
    PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/src/color/color.hh"
)
target_compile_options(color PRIVATE -Wall -Wextra -Werror)
target_link_libraries(color PUBLIC "")
target_include_directories(color PUBLIC ${SHARED_INCLUDE_DIR})

add_library(canvas OBJECT)
target_sources(canvas
    PRIVATE "src/canvas/canvas.cc"
    PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/src/canvas/canvas.hh"
)
target_compile_options(canvas PRIVATE -Wall -Wextra -Werror)
target_link_libraries(canvas PUBLIC "")
target_include_directories(canvas PUBLIC ${SHARED_INCLUDE_DIR} src/color)

add_library(matrix OBJECT)
target_sources(matrix
    PRIVATE "src/matrix/matrix.cc"
    PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/src/matrix/matrix.hh"
)
target_compile_options(matrix PRIVATE -Wall -Wextra -Werror)
target_link_libraries(matrix PUBLIC "")
target_include_directories(matrix PUBLIC ${SHARED_INCLUDE_DIR} src/tuple
                                                               src/point
                                                               src/vector)

add_library(sphere OBJECT)
target_sources(sphere
    PRIVATE "src/sphere/sphere.cc"
    PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/src/sphere/sphere.hh"
)
target_compile_options(sphere PRIVATE -Wall -Wextra -Werror)
target_link_libraries(sphere PUBLIC "")
target_include_directories(sphere PUBLIC ${SHARED_INCLUDE_DIR} src/tuple
                                                               src/point
                                                               src/vector
                                                               src/matrix
                                                               src/sphere
                                                               src/intersection
                                                               src/ray)

add_library(intersection OBJECT)
target_sources(intersection
    PRIVATE "src/intersection/intersection.cc"
    PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/src/intersection/intersection.hh"
)
target_compile_options(intersection PRIVATE -Wall -Wextra -Werror)
target_link_libraries(intersection PUBLIC "")
target_include_directories(intersection PUBLIC ${SHARED_INCLUDE_DIR} src/tuple
                                                                     src/sphere
                                                                     src/matrix)

add_library(ray OBJECT)
target_sources(ray
    PRIVATE "src/ray/ray.cc"
    PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/src/ray/ray.hh"
)
target_compile_options(ray PRIVATE -Wall -Wextra -Werror)
target_link_libraries(ray PUBLIC "")
target_include_directories(ray PUBLIC ${SHARED_INCLUDE_DIR} src/tuple
                                                            src/point
                                                            src/vector
                                                            src/sphere
                                                            src/matrix
                                                            src/intersection)

add_library(main OBJECT)
target_sources(main
    PRIVATE "src/main/main.cc"
)
target_compile_options(main PRIVATE -Wall -Wextra -Werror)
target_include_directories(main PUBLIC ${SHARED_INCLUDE_DIR}
    src/tuple
    src/point
    src/vector
    src/color
    src/canvas
    src/matrix
    src/ray
    src/sphere
    src/intersection)


add_library(test OBJECT)
target_sources(test
    PRIVATE "tests/test.cc"
)
target_compile_options(test PRIVATE -I$(CATCH_SINGLE_INCLUDE) -Wall -Wextra -Werror)
target_include_directories(test PUBLIC ${SHARED_INCLUDE_DIR})

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Tests")
    add_executable(Tests)
    target_link_libraries(Tests PRIVATE op_overloading
                                        tuple
                                        vector
                                        point
                                        color
                                        canvas
                                        matrix
                                        sphere
                                        intersection
                                        ray
                                        test)
else()
    add_executable(Raytracer)
    target_link_libraries(Raytracer PRIVATE op_overloading
                                            tuple
                                            vector
                                            point
                                            color
                                            canvas
                                            matrix
                                            sphere
                                            intersection
                                            ray
                                            main)
endif()

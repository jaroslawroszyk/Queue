cmake_minimum_required(VERSION 3.10)
project(kolejkaa CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror -Wno-unused-parameter -Wunused)

include(cmake/GTest.cmake)

add_subdirectory(kolejka)

enable_testing()
add_test(tests kolejka/tests)

add_custom_target(tests1
                  COMMAND "./kolejka/tests"
                  DEPENDS tests)

add_library(implementations src/kolejka.cpp)
target_include_directories(implementations PUBLIC include)

add_executable(tests uts/mainTest.cpp)
target_link_libraries(tests gmock_main gtest gmock implementations)

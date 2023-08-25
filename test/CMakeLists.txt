cmake_minimum_required(VERSION 3.22)

set(
        Tests
        test.cpp
)

set(
        Test_Sources
        ../src/main.cpp
)

add_executable(
        ${Tests}
        ${Test_Sources}
)

target_link_libraries(
        ${Tests}
        PUBLIC
        GTest::gtest_main
        ${PROJECT_NAME}
)
target_include_directories(CPP_EXAM PUBLIC raylib)

add_test(
        NAME ${Tests}
        COMMAND ${Tests}
)
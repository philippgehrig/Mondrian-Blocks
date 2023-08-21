cmake_minimum_required(VERSION 3.25)

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

add_test(
        NAME ${Tests}
        COMMAND ${Tests}
)
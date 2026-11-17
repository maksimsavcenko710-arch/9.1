cmake_minimum_required(VERSION 3.14)
project(lab_9_tests CXX)
set(CMAKE_CXX_STANDARD 14)

# Google Test завантажується автоматично
include(FetchContent)
FetchContent_Declare(googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)   # для Visual Studio
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

# --- Завдання 9.1: модулі без main (Lab_9_1.cpp у тести не входить) ---
# Ціль створюється, лише якщо в папці проєкту є tests_9_1.cpp
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests_9_1.cpp)
    add_executable(tests_9_1 tests_9_1.cpp var.cpp dod.cpp sum.cpp)
    target_include_directories(tests_9_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(tests_9_1 GTest::gtest_main)
    gtest_discover_tests(tests_9_1)
endif()

# --- Завдання 9.2.1: тільки macros.h ---
# Ціль створюється, лише якщо в папці проєкту є tests_9_2_1.cpp
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests_9_2_1.cpp)
    add_executable(tests_9_2_1 tests_9_2_1.cpp)
    target_include_directories(tests_9_2_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(tests_9_2_1 GTest::gtest_main)
    gtest_discover_tests(tests_9_2_1)
endif()
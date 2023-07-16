enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(test_core test_core.cc)

target_link_libraries(test_core PRIVATE GTest::gtest GTest::gtest_main core_lib)
target_include_directories(test_core PRIVATE ${CMAKE_SOURCE_DIR}/src)

add_test(AllTestsInMain test_core)
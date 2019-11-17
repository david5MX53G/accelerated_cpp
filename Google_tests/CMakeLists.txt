project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the Google_Tests_run target
add_executable(Google_Tests_run acceleratedCppTest.cpp)

# linking Google_Tests_run with bins to be tested
# target_link_libraries(Google_Tests_run cmake-build-debug)
target_link_libraries(Google_Tests_run gtest gtest_main)

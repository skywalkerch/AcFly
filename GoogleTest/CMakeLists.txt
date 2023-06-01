include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SRC TestFiles)
set(EXE ${SRC}/test_quickSort.cc)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/GoogleTest/bin)

enable_testing()
include_directories(${PROJECT_SOURCE_DIR}/lib/lib_src/include/)
include_directories(${PROJECT_SOURCE_DIR}/GoogleTest/include/)
link_directories(${PROJECT_SOURCE_DIR}/lib)
add_executable(test ${EXE} include/test.h)
target_link_libraries(
        test
        GTest::gtest_main
        AcFly
)

include(GoogleTest )
gtest_discover_tests(test)

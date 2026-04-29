# GoogleTest for core unit tests
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(coreTests
    TestSample.cpp
    ../src/Core.cpp
    ../src/CoreFactory.cpp
    ../src/HomeModule.cpp
    ../src/SettingsModule.cpp
    ../src/ConfigModule.cpp
)

target_include_directories(coreTests 
    PRIVATE 
        ../inc
        ../src/detail
)

target_link_libraries(coreTests gtest_main)

add_test(NAME coreTests COMMAND coreTests)

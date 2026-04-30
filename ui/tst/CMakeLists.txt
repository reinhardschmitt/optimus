add_executable(testcore
    TestHomeModel.cpp
    ../src/Core.cpp
    ../src/CoreFactory.cpp
    ../src/HomeModule.cpp
    ../src/SettingsModule.cpp
    ../src/ConfigModule.cpp
    ../src/Logger.cpp
    ../src/Environment.cpp
)

target_include_directories(testcore 
    PRIVATE
        .
        ../inc
        ../src/detail
)

target_link_libraries(testcore gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(testcore)

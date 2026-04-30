add_executable(testcore
    TestSample.cpp
    ../src/Core.cpp
    ../src/CoreFactory.cpp
    ../src/HomeModule.cpp
    ../src/SettingsModule.cpp
    ../src/ConfigModule.cpp
)

target_include_directories(testcore 
    PRIVATE 
        ../inc
        ../src/detail
)

target_link_libraries(testcore gtest_main)

add_test(NAME testcore COMMAND testcore)

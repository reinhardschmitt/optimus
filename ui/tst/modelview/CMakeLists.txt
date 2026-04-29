find_package(Qt6 REQUIRED COMPONENTS Test QuickTest)

add_executable(modelviewTests
    TestModelView.cpp
)

target_link_libraries(modelviewTests PRIVATE Qt6::Test core)

add_test(NAME modelviewTests COMMAND modelviewTests)

add_executable(testviewmodel
    TestModelView.cpp
)

target_link_libraries(testviewmodel PRIVATE Qt6::Test core)

add_test(NAME testviewmodel COMMAND testviewmodel)

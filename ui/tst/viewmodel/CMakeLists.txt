add_executable(testviewmodel
    TestModelView.cpp
)

target_link_libraries(testviewmodel PRIVATE Qt6::Test core)

add_test(
    NAME ViewModelUnitTests 
    COMMAND testviewmodel 
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)
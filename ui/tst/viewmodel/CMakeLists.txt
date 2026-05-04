add_executable(testviewmodel
    TestModelView.cpp
)

target_link_libraries(testviewmodel PRIVATE Qt6::Test core ui)

target_include_directories(testviewmodel PRIVATE
    ${CMAKE_SOURCE_DIR}/ui/src
    ${CMAKE_SOURCE_DIR}/ui/src/detail
    ${CMAKE_SOURCE_DIR}/ui/inc
)

add_test(
    NAME ViewModelUnitTests 
    COMMAND testviewmodel 
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)
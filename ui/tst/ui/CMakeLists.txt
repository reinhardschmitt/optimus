find_package(Qt6 REQUIRED COMPONENTS Test QuickTest)

add_executable(uiTests
    TestUi.cpp
    tst_TestUi.qml
)

target_link_libraries(uiTests PRIVATE Qt6::QuickTest Qt6::Quick core)

add_test(NAME uiTests COMMAND uiTests)

configure_file(tst_TestUi.qml tst_TestUi.qml COPYONLY)

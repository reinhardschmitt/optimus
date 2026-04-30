add_executable(testui
    TestUi.cpp
    TestUi.qml
)

target_link_libraries(testui PRIVATE Qt6::QuickTest Qt6::Quick core)

add_test(NAME testui COMMAND testui)

configure_file(TestUi.qml tst_TestUi.qml COPYONLY)

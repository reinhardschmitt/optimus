qt_add_executable(testui
    TestUi.cpp
)

qt_add_qml_module(testui
    URI "test.module"
    VERSION 1.0
    QML_FILES
        TestUi.qml
)

target_link_libraries(testui PRIVATE 
    Qt6::Quick 
    Qt6::QuickTest 
    ui
    uiplugin
)

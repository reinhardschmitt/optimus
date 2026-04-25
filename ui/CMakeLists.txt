qt_add_library(ui STATIC)

target_include_directories(ui 
    PUBLIC inc 
    PRIVATE src/detail
)

target_include_directories(ui PRIVATE ../app/inc)

qt_add_qml_module(ui
    URI "optimus.ui"
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        qml/Home.qml
        qml/Settings.qml
        qml/Config.qml
    SOURCES
        src/Navigator.cpp
        inc/Navigator.h
)

target_link_libraries(ui PRIVATE core)
qt_add_library(ui STATIC)

target_include_directories(ui 
    PUBLIC inc 
    PRIVATE src/detail
)

qt_add_qml_module(ui
    URI "optimus.ui"
    VERSION 1.0
    QML_FILES
        qml/Main.qml
    SOURCES
        src/Navigator.cpp
        src/Pages.cpp
        inc/Navigator.h
        inc/Pages.h
)

target_link_libraries(ui PRIVATE core)
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
        src/HomeViewModel.cpp
        src/detail/HomeViewModel.h
        src/SettingsViewModel.cpp
        src/detail/SettingsViewModel.h
        src/ConfigViewModel.cpp
        src/detail/ConfigViewModel.h
        inc/IViewModel.h
        src/IViewModel.cpp
)

target_link_libraries(ui PRIVATE core)

add_subdirectory(tst/qml)
add_subdirectory(tst/viewmodel)
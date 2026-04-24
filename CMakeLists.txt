cmake_minimum_required(VERSION 3.25)
project(optimus VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_QML_GENERATE_QMLLS_INI ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick QuickControls2)

qt_standard_project_setup()

add_subdirectory(core)
add_subdirectory(ui)
add_subdirectory(app)
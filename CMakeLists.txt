cmake_minimum_required(VERSION 3.25)
project(optimus VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick QuickControls2 Test QuickTest)

set(QT_QML_GENERATE_QMLLS_INI ON)
set(QT_NO_WARN_QML_MODULE_OUTPUT_DIRECTORY ON)
qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

qt_standard_project_setup()

include(CTest)
enable_testing()

add_subdirectory(core)
add_subdirectory(ui)
add_subdirectory(app)

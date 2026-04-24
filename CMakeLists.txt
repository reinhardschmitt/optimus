cmake_minimum_required(VERSION 3.16)

project(optimus VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.10)

qt_add_executable(optimus
    main.cpp
)

qt_add_qml_module(optimus
    URI optimus
    QML_FILES
        Main.qml
)

set_target_properties(optimus PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(optimus
    PRIVATE Qt6::Quick
)

install(TARGETS optimus
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

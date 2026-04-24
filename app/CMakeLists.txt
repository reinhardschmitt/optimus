# app/CMakeLists.txt

qt_add_executable(optimus src/main.cpp)

target_link_libraries(optimus 
    PRIVATE 
        ui
        uiplugin
        core
        Qt6::Core
        Qt6::Gui
        Qt6::Quick
)
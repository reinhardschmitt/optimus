add_library(core STATIC)

target_include_directories(core 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    PRIVATE 
        src/detail
)

target_sources(core
    PRIVATE
        src/Core.cpp
        src/CoreFactory.cpp
        src/HomeModule.cpp
        src/SettingsModule.cpp
        src/ConfigModule.cpp
)
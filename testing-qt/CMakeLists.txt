cmake_minimum_required(VERSION 3.16)

project(slate VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR YES)
set(CMAKE_CXX_STANDARD 17) # TODO: 20?
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

QT6_WRAP_CPP(MOC_Files
    src/Buffer.hpp
)

qt_add_executable(slate
    ./src/main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC TRUE)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt6::Core
    Qt6::Widgets
)

cmake_minimum_required(VERSION 3.16)

project(slate VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) # TODO: 20?
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(slate
    main.cpp
)
target_link_libraries(slate PRIVATE Qt6::Core)
target_link_libraries(slate PRIVATE Qt6::Widgets)

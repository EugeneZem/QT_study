cmake_minimum_required(VERSION 3.14)

project(2_main_Qt_modules LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)

add_executable(2_main_Qt_modules
  main.cpp
)
#target_link_libraries(2_main_Qt_modules Qt${QT_VERSION_MAJOR}::Core
#                                        Qt${QT_VERSION_MAJOR}::Network)

target_link_libraries(2_main_Qt_modules Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(2_main_Qt_modules Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(2_main_Qt_modules Qt${QT_VERSION_MAJOR}::Sql)

install(TARGETS 2_main_Qt_modules
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

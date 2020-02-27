cmake_minimum_required(VERSION 2.8.12)

project(system_info LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

#INCLUDE_DIRECTORIES(/usr/local/include)

#LINK_DIRECTORIES(/usr/local/lib/)

set(SOURCES
    src/sources/main.cpp
    src/sources/systeminfo.cpp
)

set(HEADERS
    src/headers/systeminfo.h
)

set(QML
    src/qml/qml.qrc
    src/qml/main.qml
    src/qml/CPU.qml
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${QML})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Core Qt5::Quick)


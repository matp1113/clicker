cmake_minimum_required(VERSION 3.16)

project(clicker VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appclicker
    main.cpp
    movingPoint.cpp
    movingPoint.h
    game.cpp
    game.h
    appRoot.cpp
    appRoot.h
    settings.cpp
    settings.h
    mainwindow.cpp
    mainwindow.h
    timer.cpp
    timer.h
    player.cpp
    player.h
    images.qrc
)

qt_add_qml_module(appclicker
    URI clicker
    VERSION 1.0
    QML_FILES main.qml game.qml settings.qml
)

set_target_properties(appclicker PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(appclicker
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(appclicker
    PRIVATE Qt6::Quick)

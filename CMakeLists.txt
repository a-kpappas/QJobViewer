cmake_minimum_required(VERSION 3.5)

project(QJobViewer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network Widgets LinguistTools)

set(TS_FILES QJobViewer_en_US.ts)

set(PROJECT_SOURCES
        main.cpp
        qjobviewer.h    qjobviewer.cpp
        jobmodel.h      jobmodel.cpp
        jobfetcher.h    jobfetcher.cpp
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QJobViewer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        testresultsmodel.h testresultsmodel.cpp
        resultsitem.h resultsitem.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QJobViewer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(QJobViewer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QJobViewer
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(QJobViewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                         Qt${QT_VERSION_MAJOR}::Network)

set_target_properties(QJobViewer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE FALSE
    WIN32_EXECUTABLE FALSE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QJobViewer)
endif()

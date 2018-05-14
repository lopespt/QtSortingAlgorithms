CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)

PROJECT(QtSortingAlgorithms)

FIND_PACKAGE(Qt5Core)
FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5OpenGL)

#IF(APPLE)
 #   INCLUDE_DIRECTORIES("/Applications/Xcode.app/Contents/Developer/Toolchains//XcodeDefault.xctoolchain/usr/include/c++/v1/")
#ENDIF(APPLE)

INCLUDE_DIRECTORIES("${Qt5Widgets_INCLUDES} ${Qt5OpenGL_INCLUDES}")
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
#set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

FILE(GLOB sources *.h *.cpp)

ADD_EXECUTABLE(QtSortingAlgorithms WIN32 ${sources})
qt5_use_modules(QtSortingAlgorithms OpenGL Widgets)

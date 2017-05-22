project(Test)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CAMKE_SOURCE_DIR}/make")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Qt REQUIRED)
#if(QT_FOUND)
#set(QT_USE_QTXML TRUE)
#include(${QT_USE_FILE})
#add_definitions(${QT_DEFINITIONS})
#include_directories(${CMAKE_CURRENT_BINARY_DIR} ${QT_INCLUDE_DIR})
#endif(QT_FOUND)

find_package(OpenCV REQUIRED)
#if(OpenCV_FOUND)
#list(APPEND ThirdParty_LIBS ${OpenCV_LIBS})
#include_directories(${OpenCV_INCLUDE_DIRS})
#endif(OpenCV_FOUND)

set(${PROJECT_NAME}_SRC main.cpp)
set(${PROJECT_NAME}_HDR )

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_HDR})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})


project(CutePad)
cmake_minimum_required(VERSION 2.8.11)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Declarative)
include_directories(${Qt5Widgets_INCLUDES})
add_definitions(${Qt5Widgets_DEFINITIONS})

# Tell CMake to create the CutePad executable
aux_source_directory(. SRC_LIST)
set(HEADER_FILES header/actions.h header/main_win.h header/main_menu.h)
set(INCLUDE_DIR ./source/ ./header/)
set(SOURCE_FILES source/actions.cpp source/main_win.cpp source/main_menu.cpp)
include_directories (${INCLUDE_DIR})
add_executable(CutePad ${SRC_LIST} ${HEADER_FILES} ${SOURCE_FILES}  ${QT_MOC})

# Use the Widgets module from Qt 5.
target_link_libraries(CutePad Qt5::Widgets)

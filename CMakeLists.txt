# CMakeLists.txt - a root build file
#
# Copyright (c) 2022 Oleg Iarygin <oleg@arhadthedev.net>
#
# Distributed under the MIT software license; see the accompanying
# file LICENSE.txt or <https://www.opensource.org/licenses/mit-license.php>.

# 3.12 for cxx_std_20 target feature support
cmake_minimum_required(VERSION 3.12)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(ProceduralHero
    VERSION 0.0.1
    HOMEPAGE_URL https://github.com/arhadthedev/procedural-hero
    LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS OpenGL OpenGLWidgets Widgets)
qt_standard_project_setup()

configure_file(src/build.h.in build.h)

add_executable(procedural-hero WIN32
    src/gui/application.cpp
    src/gui/mainwindow.cpp
    src/gui/scene_3d_view.cpp
    src/main.cpp)
target_compile_features(procedural-hero PRIVATE cxx_std_20)
target_compile_definitions(procedural-hero PRIVATE QT_NO_CAST_FROM_ASCII)
target_link_libraries(procedural-hero PRIVATE
    Qt6::OpenGL Qt6::OpenGLWidgets Qt6::Widgets)

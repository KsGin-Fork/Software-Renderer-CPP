CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
PROJECT(Software_Renderer_CPP)

SET(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE(SDL2 REQUIRED)

LINK_LIBRARIES(sdl2)

ADD_EXECUTABLE(Software_Renderer_CPP
        main.cpp
        include/matrix.hpp
        include/vector.hpp
        headers/device.h
        sources/device.cpp
        headers/color.h
        sources/color.cpp sources/timer.cpp headers/timer.h sources/camera.cpp headers/camera.h)
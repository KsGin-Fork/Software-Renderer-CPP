CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
PROJECT(Software_Renderer_CPP)

SET(CMAKE_CXX_STANDARD 14)

IF (APPLE)
    INCLUDE_DIRECTORIES(/usr/local/Cellar/sdl2/2.0.8/include)
    LINK_LIBRARIES(/usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib)
ENDIF ()

ADD_EXECUTABLE(Software_Renderer_CPP
        main.cpp
        include/matrix.hpp
        include/vector.hpp
        headers/device.h
        sources/device.cpp
        headers/color.h
        sources/color.cpp
        sources/timer.cpp
        headers/timer.h
        sources/camera.cpp
        headers/camera.h
        sources/raster.cpp
        headers/raster.h)
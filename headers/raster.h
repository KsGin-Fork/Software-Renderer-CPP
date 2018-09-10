/*
 * File   : raster
 * Author : KsGin 
 * Date   : 2018/9/5
 */

#ifndef SOFTWARE_RENDERER_CPP_RASTER_H
#define SOFTWARE_RENDERER_CPP_RASTER_H

#include "device.h"
#include "../include/vector.hpp"

/**
 * raster class
 */
class Raster {

    typedef Math::Vector2 Point2;

    /**
     * device
     */
    Device *device;
public:
    /**
     * empty constructor (deleted)
     */
    Raster() = delete;

    /**
     * constructor
     * @param device parameter
     */
    explicit Raster(Device *device);

    /**
     * raster line
     */
    void RasterLine(const Raster::Point2 &p1, const Raster::Point2 &p2 , const Color &color);
};


#endif //SOFTWARE_RENDERER_CPP_RASTER_H

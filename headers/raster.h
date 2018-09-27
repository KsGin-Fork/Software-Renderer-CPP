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

    /**
     * device
     */
    Device *device;
public:

    /**
     * raster type
     */
    enum TYPE {
        /**
         * solid
         */
        SOLID = 1,
        /**
         * wire
         */
        WIRE = 2
    };


    /**
     * declare point2
     */
    typedef Math::Vector2 Point2;

    /**
     * declare point3
     */
    typedef Math::Vector3 Point3;

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
     * model raster
     */
    void RasterModel(Point2 &p1, Point2 &p2, Point2 &p3 , const Color& color , const TYPE& type);

    /**
     * raster line
     */
    void RasterLine(const Raster::Point2 &p1, const Raster::Point2 &p2, const Color &color);

    /**
     * solid raster
     */
    void RasterTriangle(const Point2 &p1, const Point2 &p2, const Point2 &p3 , const Color& color);

    /**
     * interpolate int
     */
    int Interpolate(const int &val1, const int &val2, const float &gradient);

    /**
     * interpolate point
     */
    Point2 Interpolate(const Point2 &val1, const Point2 &val2, const float &gradient);

    /**
     * interpolate point3
     */
    Point3 Interpolate(const Point3 &val1, const Point3 &val2, const float &gradient);

    /**
     * fixed position
     */
    void FixPosition2D(Point2 &point);

};


#endif //SOFTWARE_RENDERER_CPP_RASTER_H

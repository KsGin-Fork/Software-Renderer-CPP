/*
 * File   : raster
 * Author : KsGin 
 * Date   : 2018/9/5
 */

#include "../headers/raster.h"

Raster::Raster(Device *device) {
    this->device = device;
}

void Raster::RasterModel(Raster::Point2 &p1, Raster::Point2 &p2, Raster::Point2 &p3, const Color &color, const TYPE& type) {
    this->FixPosition2D(p1);
    this->FixPosition2D(p2);
    this->FixPosition2D(p3);

    if(type == TYPE::SOLID) {
        this->RasterTriangle(p1 , p2 , p3 , color);
    } else {
        this->RasterLine(p1 , p2 , color);
        this->RasterLine(p2 , p3 , color);
        this->RasterLine(p1 , p3 , color);
    }
}

void Raster::RasterTriangle(const Raster::Point2 &p1, const Raster::Point2 &p2, const Raster::Point2 &p3,
                            const Color &color) {

}

void Raster::RasterLine(const Raster::Point2 &p1, const Raster::Point2 &p2, const Color &color) {
    int x1 = static_cast<int>(p1._x);
    int y1 = static_cast<int>(p1._y);
    int x2 = static_cast<int>(p2._x);
    int y2 = static_cast<int>(p2._y);
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    while (true) {
        device->setPixelColor(x1, y1, color);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int Raster::Interpolate(const int &val1, const int &val2, const float &gradient) {
    return static_cast<int>((val1 < val2 ? val1 : val2) + abs(val1 - val2) * gradient);
}

Raster::Point2 Raster::Interpolate(const Raster::Point2 &val1, const Raster::Point2 &val2, const float &gradient) {
    return Point2(
    static_cast<int>((val1._x < val2._x ? val1._x : val2._x) + abs(val1._x - val2._x) * gradient),
    static_cast<int>((val1._y < val2._y ? val1._y : val2._y) + abs(val1._y - val2._y) * gradient)
    );
}

Raster::Point3 Raster::Interpolate(const Raster::Point3 &val1, const Raster::Point3 &val2, const float &gradient) {
    return Raster::Point3(
    static_cast<int>((val1._x < val2._x ? val1._x : val2._x) + abs(val1._x - val2._x) * gradient),
    static_cast<int>((val1._y < val2._y ? val1._y : val2._y) + abs(val1._y - val2._y) * gradient),
    static_cast<int>((val1._z < val2._z ? val1._z : val2._z) + abs(val1._z - val2._z) * gradient)
    );
}

void Raster::FixPosition2D(Raster::Point2 &point) {
    point._x = point._x * device->width + device->width / 2;
    point._y = -point._y * device->height + device->height / 2;
}



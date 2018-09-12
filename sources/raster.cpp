/*
 * File   : raster
 * Author : KsGin 
 * Date   : 2018/9/5
 */

#include "../headers/raster.h"

Raster::Raster(Device *device) {
    this->device = device;
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

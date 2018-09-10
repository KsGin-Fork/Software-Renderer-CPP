#include <iostream>
#include <sstream>
#include "headers/device.h"
#include "headers/timer.h"
#include "headers/raster.h"

using namespace std;

const int windowWidth = 800;
const int windowHeight = 600;
const bool windowIsFullScreen = false;
const long SECOND_TO_MICROSECOND = 1000000;

int main() {

    string windowTitle = "Software Renderer FPS: ";

    auto *device = new Device();

    device->initialize(windowWidth, windowHeight, windowIsFullScreen);

    auto *timer = new Timer();

    device->show();

    auto *raster = new Raster(device);

    while (!device->windowShouldClose()) {
        timer->doTimerStart();

        device->handleEvent();

        raster->RasterLine(Math::Vector2(100, 100), Math::Vector2(500, 500), Color::white());

        device->updateRender();

        timer->doTimerEnd();
        device->updateWindowTitle((windowTitle + to_string(SECOND_TO_MICROSECOND / (timer->duration()))).c_str());
    }

    device->destory();
    delete device;
    delete timer;

    return 0;
}
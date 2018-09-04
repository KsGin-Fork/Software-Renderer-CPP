#include <iostream>
#include "headers/device.h"

int main() {

    auto *device = new Device();

    device->initialize(800, 600, false);
    device->show();

    while (!device->windowShouldClose()) {
        device->handleEvent();
    }

    device->destory();
    delete device;

    return 0;
}
/*
 * File   : timer
 * Author : KsGin 
 * Date   : 2018/9/4
 */

#include "../headers/timer.h"

void Timer::doTimerStart() {
    start = std::chrono::high_resolution_clock::now();
}

void Timer::doTimerEnd() {
    end = std::chrono::high_resolution_clock::now();
}

long Timer::duration() {
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() + 1;
}

/*
 * File   : timer
 * Author : KsGin 
 * Date   : 2018/9/4
 */

#ifndef SOFTWARE_RENDERER_CPP_TIMER_H
#define SOFTWARE_RENDERER_CPP_TIMER_H

#include <chrono>

/**
 * Timer
 */
class Timer {
private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
public:

    void doTimerStart();

    void doTimerEnd();

    long duration();

};


#endif //SOFTWARE_RENDERER_CPP_TIMER_H

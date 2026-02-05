#ifndef _TIMER_H_
#define _TIMER_H_
#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <vector>
#include <algorithm>
#include <iomanip>
class Timer
{
private:
    double interval;
    std::vector<std::chrono::system_clock::time_point> memory; // time point
    std::vector<std::chrono::system_clock::duration> distance; // interval

public:
    Timer(double interval_out);
    // initailization
    void timer();

    void info_printer();
};
#endif
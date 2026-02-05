#include "../include/timer.h"

const auto second = std::chrono::seconds(1);

Timer::Timer(double interval_out) : interval(interval_out)
{
    memory.reserve(101);
    distance.reserve(100);
}
// initailization
void Timer::timer()
{ // clear the vector
    memory.clear();
    distance.clear();
    // timer
    auto begin = std::chrono::system_clock::now();
    auto begin_time = std::chrono::system_clock::to_time_t(begin);
    std::cout << "Current date and time: " << std::ctime(&begin_time);
    memory.push_back(begin); // add time point
    int count = 0;
    while (count < 100)
    {
        std::this_thread::sleep_for(interval * second);
        auto now = std::chrono::system_clock::now();
        memory.push_back(now);
        auto print_time = std::chrono::system_clock::to_time_t(now);
        std::cout << "Current date and time: " << std::ctime(&print_time);
        count++;
    }

    // process the distance
    for (int i = 0; i < 100; i++)
    {
        distance.push_back(memory[i + 1] - memory[i]);
    }
    // arrange sequence
    std::sort(distance.begin(), distance.end());
}

void Timer::info_printer()
{
    if (memory.empty())
        std::cout << "Use the timer function first" << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(3);

        auto average_interval = (memory[100] - memory[0]) / 100;
        auto avg_ms = std::chrono::duration_cast<std::chrono::milliseconds>(average_interval);
        std::cout << "Average interval " << avg_ms.count() / 1000.0 << " seconds" << std::endl;

        auto p50_ms = std::chrono::duration_cast<std::chrono::milliseconds>(distance[49]);
        std::cout << "P50 " << p50_ms.count() / 1000.0 << " seconds" << std::endl;

        auto p80_ms = std::chrono::duration_cast<std::chrono::milliseconds>(distance[79]);
        std::cout << "P80 " << p80_ms.count() / 1000.0 << " seconds" << std::endl;

        auto p90_ms = std::chrono::duration_cast<std::chrono::milliseconds>(distance[89]);
        std::cout << "P90 " << p90_ms.count() / 1000.0 << " seconds" << std::endl;

        auto p95_ms = std::chrono::duration_cast<std::chrono::milliseconds>(distance[94]);
        std::cout << "P95 " << p95_ms.count() / 1000.0 << " seconds" << std::endl;

        auto p99_ms = std::chrono::duration_cast<std::chrono::milliseconds>(distance[98]);
        std::cout << "P99 " << p99_ms.count() / 1000.0 << " seconds" << std::endl;
    }
}

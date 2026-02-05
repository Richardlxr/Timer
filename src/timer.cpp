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
    auto begin_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(begin.time_since_epoch()).count() % 1000000000;
    std::tm *tm_info = std::localtime(&begin_time);
    std::cout << "Current timestamp: " << std::put_time(tm_info, "%Y-%m-%d %H:%M:%S")
              << "." << std::setfill('0') << std::setw(9) << begin_ns << std::endl;
    memory.push_back(begin); // add time point
    int count = 0;
    while (count < 100)
    {
        std::this_thread::sleep_for(interval * second);
        auto now = std::chrono::system_clock::now();
        memory.push_back(now);
        auto print_time = std::chrono::system_clock::to_time_t(now);
        auto now_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count() % 1000000000;
        std::tm *tm_now = std::localtime(&print_time);
        std::cout << "Current timestamp: " << std::put_time(tm_now, "%Y-%m-%d %H:%M:%S")
                  << "." << std::setfill('0') << std::setw(9) << now_ns << std::endl;
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
        std::cout << std::fixed << std::setprecision(10);

        auto average_interval = (memory[100] - memory[0]) / 100;
        auto avg_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(average_interval);
        std::cout << "Average interval " << avg_ns.count() / 1000000000.0 << " seconds" << std::endl;

        auto p50_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(distance[49]);
        std::cout << "P50 " << p50_ns.count() / 1000000000.0 << " seconds" << std::endl;

        auto p80_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(distance[79]);
        std::cout << "P80 " << p80_ns.count() / 1000000000.0 << " seconds" << std::endl;

        auto p90_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(distance[89]);
        std::cout << "P90 " << p90_ns.count() / 1000000000.0 << " seconds" << std::endl;

        auto p95_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(distance[94]);
        std::cout << "P95 " << p95_ns.count() / 1000000000.0 << " seconds" << std::endl;

        auto p99_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(distance[98]);
        std::cout << "P99 " << p99_ns.count() / 1000000000.0 << " seconds" << std::endl;
    }
}

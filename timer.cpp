#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <vector>
#include <algorithm>
#include <iomanip>

const auto second = std::chrono::seconds(1);

class Timer
{
private:
    double interval;
    std::vector<std::chrono::system_clock::time_point> memory; // time point
    std::vector<std::chrono::system_clock::duration> distance; // interval

public:
    Timer(double interval_out) : interval(interval_out)
    {
        memory.reserve(101);
        distance.reserve(100);
    }
    // initailization
    void timer()
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
        auto end = std::chrono::system_clock::now();

        // process the distance
        for (int i = 0; i < 100; i++)
        {
            distance.push_back(memory[i + 1] - memory[i]);
        }
        // arrange sequence
        std::sort(distance.begin(), distance.end());
    }

    void info_printer()
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
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <interval>\n";
        std::cout << "eg: " << argv[0] << " 1.0\n";
        std::cout << "eg: " << argv[0] << " 0.5\n";
        return 1;
    }

    double interval = std::atof(argv[1]);
    if (interval <= 0)
    {
        std::cout << "Error: Interval time must be greater than 0\n";
        return 1;
    }

    Timer myTimer(interval);
    myTimer.timer();
    myTimer.info_printer();

    return 0;
}
#include "include/timer.h"

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
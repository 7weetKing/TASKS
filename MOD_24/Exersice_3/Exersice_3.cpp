#include <iostream>
#include <iomanip>
#include <ctime>

void sleep_one_second() {
    std::time_t start = std::time(nullptr);
    while (std::time(nullptr) == start);
}

int main() {
    std::cout << "Enter the time in mm:ss: ";

    int minutes, seconds;
    std::tm input_time = {};

    std::cin >> std::get_time(&input_time, "%M:%S");
    if (std::cin.fail()) {
        std::cerr << "Input error! Use the mm:ss format." << std::endl;
        return 1;
    }

    minutes = input_time.tm_min;
    seconds = input_time.tm_sec;

    std::time_t now = std::time(nullptr);
    std::time_t end_time = now + minutes * 60 + seconds;

    while (std::time(nullptr) < end_time) {
        std::time_t remaining = end_time - std::time(nullptr);
        int remaining_minutes = remaining / 60;
        int remaining_seconds = remaining % 60;

        std::cout << "There's still time left: " << remaining_minutes << ":" << remaining_seconds << "\n";

        sleep_one_second();
    }

    std::cout << "DING! DING! DING!" << std::endl;
    return 0;
}
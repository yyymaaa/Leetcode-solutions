#include <iostream>
#include <cmath>

double angleClock(int hour, int minutes) {
    if (hour == 12) {
        hour = 0;
    }

    double hourAngle = (hour * 30.0) + (minutes * 0.5);
    double minuteAngle = minutes * 6.0;

    double diff = abs(hourAngle - minuteAngle);

    if (diff > 180.0) {
        return 360.0 - diff;
    }

    return diff;
}

int main() {
    std::cout << "Test 1 (12:30): " << angleClock(12, 30) << " degrees" << std::endl;

    std::cout << "Test 2 (3:30): " << angleClock(3, 30) << " degrees" << std::endl;

    std::cout << "Test 3 (3:15): " << angleClock(3, 15) << " degrees" << std::endl;

    return 0;
}
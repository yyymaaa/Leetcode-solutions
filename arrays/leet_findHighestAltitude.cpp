#include <iostream>
#include <vector>
int largestAltitude(std::vector<int>& gain) {
        int current_altitude = 0;
        int highest_altitude = 0;

        for(int g : gain) {
            current_altitude += g;
            if (current_altitude > highest_altitude) {
                highest_altitude = current_altitude;
            }
        }

        return highest_altitude;
    }

int main() {
    std::vector<int> gain1 = {-5, 1, 5, 0, -7};
    std::cout << "Test 1: " << largestAltitude(gain1) << std::endl;

    std::vector<int> gain2 = {-4, -3, -2, -1, 4, 3, 2};
    std::cout << "Test 2: " << largestAltitude(gain2) << std::endl;

    return 0;
}
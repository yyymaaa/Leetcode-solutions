#include <iostream>
#include <string>
#include <algorithm>


int minPartitions(std::string n) {
        char maxDigit = *std::max_element(n.begin(), n.end());

        return maxDigit - '0'; //if we return maxDigit only, it will return the ASCII character of the maxDigit
    }

int main() {
    std::string n = "82734";
    int result = minPartitions(n);

    std::cout << "The minimum deci-binary numbers needed: " << result << std::endl;

    return 0;
}
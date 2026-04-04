#include <iostream>
#include <string>
#include <algorithm>

int minOperations(std::string s) {
        int flipsForZero = 0;
        int flipsForOne = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] != '0') {
                    flipsForZero++;
                }
            } else {
                if (s[i] != '1') {
                    flipsForZero++;
                }
            }
        }
        flipsForOne = n - flipsForZero;

        int final = std::min(flipsForOne, flipsForZero);
        return final;
    }

int main() {
    std::string s = "1111";

    int result = minOperations(s);

    std::cout << "Input string: " << s << std::endl;
    std::cout << "Minimum operations needed: " << result << std::endl;


    return 0;
}
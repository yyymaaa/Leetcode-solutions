#include <iostream>
#include <string>

int numSteps(std::string s) {
    int i = 0;
    while (s != "1") {
        if (s[s.length() - 1] == '0') {
            s.pop_back(); //shifting everything to the right is the same as dividing by 2
        } else {
            int x = s.length() - 1;
            while (x >= 0 && s[x] == '1') {
                s[x] = '0';
                x--;
            } 
            if (x >= 0) {
                s[x] = '1';
            } else {
                s = '1' + s;
            }
        }
        i++;
    }
    return i;
}

int main() {
    std::string s1 = "1101"; // Expected: 6
    std::string s2 = "10";   // Expected: 1
    std::string s3 = "1";    // Expected: 0

    std::cout << "Input: 1101 | Output: " << numSteps(s1) << std::endl;
    std::cout << "Input: 10   | Output: " << numSteps(s2) << std::endl;
    std::cout << "Input: 1    | Output: " << numSteps(s3) << std::endl;

    return 0;
}
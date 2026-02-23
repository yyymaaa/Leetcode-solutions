#include <iostream>
#include <unordered_set>
#include <cmath>

class Solution {
public:
    bool hasAllCodes(std::string s, int k) {
        if (s.size() < k) return false;
        int uniqueStrings = pow(2, k);
        std::unordered_set<std::string> ourSet;
        for (int i =0; i<= (int)s.size() - k; i++) {
            ourSet.insert(s.substr(i, k));
        }
        if (ourSet.size() == uniqueStrings) {
            return true;
        } 

      return ourSet.size() == uniqueStrings;
    }
};

int main() {
    Solution solver;

    std::string s1 = "00110110";
    int k1 = 2;
    std::cout << "Test 1 (s=\"00110110\", k=2): " << (solver.hasAllCodes(s1, k1) ? "True" : "False") << std::endl;

    std::string s2 = "0110";
    int k2 = 1;
    std::cout << "Test 2 (s=\"0110\", k=1): " << (solver.hasAllCodes(s2, k2) ? "True" : "False") << std::endl;

    std::string s3 = "0110";
    int k3 = 2;
    std::cout << "Test 3 (s=\"0110\", k=2): " << (solver.hasAllCodes(s3, k3) ? "True" : "False") << std::endl;

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

char processStr(std::string s, long long k) {
        long long m = 0;

        for(char c: s) {
            if (c == '*') {
                m = std::max(0LL, m - 1);
            } else if (c == '#') {
                m <<= 1;
            } else if (c != '%') {
                m += 1;
            }
        }

        if (k >= m) return '.';

        for (int i = s.length() - 1; ; i--) {
            char c = s[i];
            if (c == '*') {
                m += 1;
            } else if (c == '#') {
                m /=2;
                if (k >= m) {
                    k -= m;
                }
            } else if (c == '%') {
                k = m - 1 - k;
            } else {
                m -= 1;
                if (k == m) {
                    return c;
                }
        }
    }
}

int main() {
    std::string s1 = "a#b%*";
    long long k1 = 1;
    std::cout << "Test 1: " << processStr(s1, k1) << std::endl;

    std::string s2 = "cd%#*#";
    long long k2 = 3;
    std::cout << "Test 2: " << processStr(s2, k2) << std::endl;

    std::string s3 = "z*#";
    long long k3 = 0;
    std::cout << "Test 3: " << processStr(s3, k3) << std::endl;

    return 0;
}
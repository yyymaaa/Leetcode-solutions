#include <iostream>
#include <string>

long long sumAndMultiply(int n) {
    std::string n_str = std::to_string(n);    
    std::string x_str = "";
    
    for(char c: n_str) {
        if (c != '0') {
            x_str += c;
        }
    }

    if (x_str.empty()) {
        return 0;
    }

    long long x = std::stoll(x_str);

    long long digit_sum = 0;
    for (char c : x_str) {
        digit_sum += (c - '0');
    }

    return x * digit_sum;
}

int main() {
    std::cout << "Test 1: " << sumAndMultiply(10203004) << std::endl; 
    std::cout << "Test 2: " << sumAndMultiply(1000) << std::endl;     
    return 0;
}
#include <iostream>
#include <cmath>

char findKthBit(int n, int k) {
    if (n == 1) return '0';
    int length = (1 << n) - 1; 
    int middle = length / 2 + 1;
    if (k == middle) {
        return '1';
    } else if (k < middle) {
        return findKthBit(n - 1, k);
    } else {
        char mirrorBit = findKthBit(n - 1, length - k + 1);
        return (mirrorBit == '0') ? '1' : '0';
    }
}

int main() {
    std::cout << "Result: " << findKthBit(4, 11) << std::endl; 
    return 0;
}
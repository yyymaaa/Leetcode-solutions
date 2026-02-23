#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

//goal here is to find the element in the array that doesn't have a matching partner

int solution(std::vector<int> &A) {
    int N = A.size();
    int result = 0;
    
    for (int i = 0; i < N; i++ ) {
       result = result ^ A[i];
    }
    
    return result; 
}

int main() {
    // Test Case 1: 9 is the lonely one
    std::vector<int> test1 = {9, 3, 9, 3, 7, 4, 4};
    std::cout << "Lonely number in Test 1: " << solution(test1) << std::endl;

    // Test Case 2: An array with just one element
    std::vector<int> test2 = {42};
    std::cout << "Lonely number in Test 2: " << solution(test2) << std::endl;

    return 0;
}
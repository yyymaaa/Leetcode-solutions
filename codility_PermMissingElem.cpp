#include <iostream>
#include <vector>

int solution(std::vector<int> &A) {
    long long N = A.size();
    long long actualSum = 0;
    long long perfectSum =  ((N + 1) * (N + 2)) / 2; //Gauss formula
    for (int i = 0; i < N; i++) {
        actualSum = actualSum + A[i];
    }

    int missingElement = perfectSum - actualSum;
    return missingElement;
}

int main() {
    std::vector<int> testArray = {2, 3, 1, 5};

    int missing = solution(testArray);

    std::cout << "Array: [2, 3, 1, 5]" << std::endl;
    std::cout << "The missing element is: " << missing << std::endl;

    return 0;
}
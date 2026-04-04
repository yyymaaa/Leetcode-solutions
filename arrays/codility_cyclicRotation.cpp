#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

// A = [3, 8, 9, 7, 6] when rotated K=1 times, you get A = [6, 3, 8, 9, 7]
// GOAL: Rotate Array A, K times

std::vector<int> solution(std::vector<int> &A, int K) {
    int N = A.size();
    if (A.empty()) return A;

    K = K % N; // saves the computer from doing useless laps
    if (K == 0) return A;

    //LONG SOLUTION
    // for (int rotation = 0; rotation < K; rotation++) {
    //     int lastElement = A[N-1];

    //     for (int i = N - 1; i > 0; i--) {
    //         A[i] = A[i - 1];
    //     }

    //     A[0] lastElement;

    // }


    //SHORTCUT
    std::vector<int> result(N);
    for (int i = 0; i < N; i++) {
        int newPosition = (i + K) % N;
        result[newPosition] = A[i];
    }

 

    return result;
}


int main() {
    // Example test case
    std::vector<int> A = {3, 8, 9, 7, 6};
    int K = 3;

    std::vector<int> rotatedA = solution(A, K);

   
    std::cout << "Rotated Array: [ ";
    for (int x : rotatedA) {
        std::cout << x << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}


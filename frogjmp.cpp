#include <iostream>

//D is the stride, X is the initial position, Y is the target position
int solution(int X, int Y, int D) {
    if (X >= Y) return 0;
    int distanceToCover = Y - X;
    int jumps = (distanceToCover + D - 1) / D;  //we add D-1 to the tota; dist to cause a round up

    return jumps;
}

int main() {
    // Frog lands a little past the finish line
    std::cout << "Test 1 (X=10, Y=85, D=30): " << solution(10, 85, 30) << " jumps" << std::endl;
    
    // Frog lands exactly at the finish line
    std::cout << "Test 2 (X=10, Y=100, D=30): " << solution(10, 100, 30) << " jumps" << std::endl;

    // Frog is past the finish line
    std::cout << "Test 3 (X=100, Y=10, D=30): " << solution(100, 10, 30) << " jumps" << std::endl;

    return 0;
}

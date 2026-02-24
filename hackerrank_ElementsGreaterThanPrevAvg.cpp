//here, we are to return the number of elements that are strictly greater than the average of previous elements
//ignore the first element
// second element: Average is the first element
// our variables: prevAvg, elementCount, 
#include <iostream>
#include <vector>

int countResponseTimeRegressions(std::vector<int> responseTimes) {
    if (responseTimes.empty()) return 0;
    long long sum = responseTimes[0];
    int finalCount = 0;
  
    for (int i = 1; i < responseTimes.size(); i++) {
        if (responseTimes[i] * (long long)i > sum) {
            finalCount++;
        }

        sum = sum + responseTimes[i];
    }
    return finalCount;
}

int main() {
    int n;
    if (!(std::cin >> n)) return 0;

    if (n <= 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> responseTimes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> responseTimes[i];
    }

    int result = countResponseTimeRegressions(responseTimes);
    std::cout << result << std::endl;

    return 0;
}
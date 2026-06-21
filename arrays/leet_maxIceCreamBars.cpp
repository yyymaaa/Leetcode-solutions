#include <iostream>
#include <vector>
#include <algorithm>

int maxIceCream(std::vector<int>& costs, int coins) {
        int max_price = 0;
        for (int cost : costs) {
            max_price = std::max(max_price, cost);
        }

        std::vector<int> frequency(max_price + 1, 0);

        for (int cost: costs) {
            frequency[cost]++;
        }

        int bars_bought = 0;

        for (int price = 1; price <= max_price; price++) {
            if (frequency[price] == 0) {
                continue;
            }

            long long total_cost_for_this_price = (long long)price * frequency[price];

            if(coins >= total_cost_for_this_price) {
                coins -= total_cost_for_this_price;
                bars_bought += frequency[price];
            } else {
                int bars_we_can_afford = coins / price;
                bars_bought += bars_we_can_afford;
                break;
            }
        }
        return bars_bought;
    }

    int main() {
    std::vector<int> costs1 = {1, 3, 2, 4, 1};
    int coins1 = 7;
    std::cout << "Test 1: " << maxIceCream(costs1, coins1) << std::endl;

    std::vector<int> costs2 = {10, 6, 8, 7, 7, 8};
    int coins2 = 5;
    std::cout << "Test 2: " << maxIceCream(costs2, coins2) << std::endl;

    std::vector<int> costs3 = {1, 6, 3, 1, 2, 5};
    int coins3 = 20;
    std::cout << "Test 3: " << maxIceCream(costs3, coins3) << std::endl;

    return 0;
}
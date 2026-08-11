#include <vector>
#include <algorithm>

class Solution {
public:
    double minPrice(std::vector<int>& prices, std::vector<int>& discounts) {
        // Step 1: Sort both arrays in descending order
        std::sort(prices.rbegin(), prices.rend());
        std::sort(discounts.rbegin(), discounts.rend());
        
        double total_price = 0.0;
        int n = prices.size();
        int m = discounts.size();
        
        // Step 2: Apply largest discounts to largest prices
        for (int i = 0; i < n; ++i) {
            if (i < m) {
                total_price += prices[i] * (100.0 - discounts[i]) / 100.0;
            } else {
                total_price += prices[i]; // No discount available
            }
        }
        
        return total_price;
    }
};
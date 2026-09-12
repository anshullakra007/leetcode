auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        // Always iterate over the item with the higher price to minimize loop passes
        int max_cost = max(cost1, cost2);
        int min_cost = min(cost1, cost2);
        
        long long ways = 0;
        for (int rem = total; rem >= 0; rem -= max_cost) {
            ways += (rem / min_cost) + 1;
        }
        
        return ways;
    }
};
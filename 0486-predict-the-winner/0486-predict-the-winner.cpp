

class Solution {
public:
    bool predictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        
        // dp[j] will represent the maximum score difference Player 1 can achieve 
        // over Player 2 for the subarray nums[i...j].
        std::vector<int> dp(n, 0);

        // Base case: Subarrays of length 1 (i == j)
        for (int i = 0; i < n; ++i) {
            dp[i] = nums[i];
        }

        // Fill DP table for larger subarray lengths from right to left
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                // Taking nums[i] leaves range [i+1, j]
                // Taking nums[j] leaves range [i, j-1]
                dp[j] = std::max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }

        // Player 1 wins if the max score difference for nums[0...n-1] is >= 0
        return dp[n - 1] >= 0;
    }
};
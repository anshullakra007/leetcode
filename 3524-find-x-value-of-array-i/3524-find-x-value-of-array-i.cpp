class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int v = num % k;
            vector<long long> next_dp(k, 0);

            // Extend existing subarrays ending at the previous position
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    next_dp[(r * v) % k] += dp[r];
                }
            }

            // Start a new single-element subarray
            next_dp[v]++;

            // Accumulate counts to final answer
            for (int r = 0; r < k; ++r) {
                ans[r] += next_dp[r];
            }

            dp = move(next_dp);
        }

        return ans;
    }
};
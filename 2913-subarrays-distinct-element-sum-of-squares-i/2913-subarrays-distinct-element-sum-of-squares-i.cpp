class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int totalScore = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            unordered_set<int> basket;
            for (int j = i; j < n; j++) {
                basket.insert(nums[j]);
                int count = basket.size();
                totalScore += count * count;
            }
        }

        return totalScore;
    }
};


class Solution {
private:
    // Helper function returning max relative score difference player can get from nums[i...j]
    int maxDiff(const std::vector<int>& nums, int i, int j) {
        // Base case: only one element left
        if (i == j) {
            return nums[i];
        }

        // Pick left element OR right element
        int takeLeft = nums[i] - maxDiff(nums, i + 1, j);
        int takeRight = nums[j] - maxDiff(nums, i, j - 1);

        return std::max(takeLeft, takeRight);
    }

public:
    bool predictTheWinner(std::vector<int>& nums) {
        return maxDiff(nums, 0, nums.size() - 1) >= 0;
    }
};
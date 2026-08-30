class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int min_idx = min_element(nums.begin(), nums.end()) - nums.begin();
        int max_idx = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(min_idx, max_idx);
        int right = max(min_idx, max_idx);

        int remove_both_front = right + 1;
        int remove_both_back = n - left;
        int remove_both_sides = (left + 1) + (n - right);

        return min({remove_both_front, remove_both_back, remove_both_sides});
    }
};
class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> seen;
        
        for (int i = 0; i < nums.size(); i++) {
            // Check if the current number was seen before
            if (seen.find(nums[i]) != seen.end()) {
                // Check if the distance between indices is <= k
                if (i - seen[nums[i]] <= k) {
                    return true;
                }
            }
            // Update the last seen index of nums[i]
            seen[nums[i]] = i;
        }
        
        return false;
    }
};
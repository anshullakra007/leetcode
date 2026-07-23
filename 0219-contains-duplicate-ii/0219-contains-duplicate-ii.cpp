#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_set<int> window;
        
        for (int i = 0; i < nums.size(); i++) {
            // Check if current element is in our sliding window
            if (window.count(nums[i])) {
                return true;
            }
            
            window.insert(nums[i]);
            
            // Keep window size at most k
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};
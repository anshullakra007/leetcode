class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxNum = nums[0];
        for (int &num: nums) {
            maxNum = max(maxNum, num);
            num = gcd(num, maxNum);

        }
        sort(nums.begin(), nums.end());

        int lo = 0;
        int hi = nums.size()-1;
        long long sum = 0;
        while(lo<hi){
            sum += gcd(nums[hi],nums[lo]);
            lo++;
            hi--;
        }
        return sum;
    }
};
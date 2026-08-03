class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi=0,maxsum=nums[0],mini=0,minsum=nums[0],total=0;
        for(int x: nums){
            maxi=max(x,maxi+x);
            maxsum=max(maxsum,maxi);
            mini=min(x,mini+x);
            minsum=min(minsum,mini);
            total+=x;
        }
        if (maxsum<0)return maxsum;
        return max(maxsum,total-minsum);
        
    }
};
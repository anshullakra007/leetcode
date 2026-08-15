class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            totalXor ^= x;
            if (x != 0) {
                hasNonZero = true;
            }
        }

        // Agar saare elements hi 0 hain
        if (!hasNonZero) {
            return 0;
        }

        // Agar pure array ka XOR already non-zero hai
        if (totalXor != 0) {
            return nums.size();
        }

        // Agar pure array ka XOR 0 hai, par non-zero element exist karta hai
        return nums.size() - 1;
    }
};
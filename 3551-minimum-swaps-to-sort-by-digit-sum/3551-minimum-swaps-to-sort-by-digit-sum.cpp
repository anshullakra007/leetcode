class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // 1. Make a copy and sort it according to the problem rule
        vector<int> target = nums;
        sort(target.begin(), target.end(), [&](int a, int b) {
            int sumA = getDigitSum(a);
            int sumB = getDigitSum(b);
            if (sumA != sumB) return sumA < sumB;
            return a < b;
        });

        // 2. Track where each number currently lives in nums
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        int swaps = 0;

        // 3. Go left to right: put the right number into index i
        for (int i = 0; i < n; i++) {
            // While position i doesn't have the element that belongs there
            while (nums[i] != target[i]) {
                int correctNum = target[i];
                int correctNumPos = pos[correctNum];

                // Swap nums[i] with the element at correctNumPos
                pos[nums[i]] = correctNumPos;
                pos[correctNum] = i;

                swap(nums[i], nums[correctNumPos]);
                swaps++;
            }
        }

        return swaps;
    }
};
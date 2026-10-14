class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Impossible if sum exceeds the maximum num digits can hold
        if (sum > 9LL * num) return "";

        int nines = sum / 9;
        int rem = sum % 9;

        string ans = "";
        // Pre-allocate to avoid reallocations with num up to 2 * 10^5
        ans.reserve(num);

        // 1. Append all 9s
        ans.append(nines, '9');

        // 2. Append the remainder digit if needed
        if (rem > 0) {
            ans.push_back('0' + rem);
        }

        // 3. Pad the rest with 0s until length reaches num
        if ((int)ans.size() < num) {
            ans.append(num - ans.size(), '0');
        }

        return ans;
    }
};
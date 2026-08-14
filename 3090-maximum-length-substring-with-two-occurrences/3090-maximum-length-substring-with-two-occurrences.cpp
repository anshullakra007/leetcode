class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int max_len = 0;
        vector<int> count(26, 0);

        for (int right = 0; right < s.length(); right++) {
            count[s[right] - 'a']++;

            // Agar current character ka count 2 se zyada ho jaye,
            // toh window ko left se shrink karo jab tak valid na ho jaye
            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }

            // Valid window size update karo
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
        
    }
};
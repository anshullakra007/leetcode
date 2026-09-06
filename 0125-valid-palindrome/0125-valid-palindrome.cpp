class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            // Skip non-alphanumeric characters from the left
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            // Skip non-alphanumeric characters from the right
            while (l < r && !isalnum(s[r])) {
                r--;
            }

            // Compare case-insensitively
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};
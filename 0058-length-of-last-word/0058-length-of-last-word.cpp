class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int length = 0;

        // 1. Skip trailing spaces at the end
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // 2. Count characters of the last word until the next space
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
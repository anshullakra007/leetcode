class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++; // Only advance s pointer when a match is found
            }
            j++;     // Always advance t pointer
        }
        
        // If i reached the end of s, all characters were matched in order
        return i == s.length();
    }
};
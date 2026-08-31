class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCount = 0;
        
        for (char c : word) {
            if (isupper(c)) {
                upperCount++;
            }
        }
        
        return upperCount == word.length() || 
               upperCount == 0 || 
               (upperCount == 1 && isupper(word[0]));
    }
};
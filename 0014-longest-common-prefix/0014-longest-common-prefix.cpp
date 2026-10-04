class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Strings ko lexicographical order me sort karein
        sort(strs.begin(), strs.end());
        
        string first = strs[0];
        string last = strs.back();
        string ans = "";
        
        // First aur last string ko compare karein
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                break;
            }
            ans += first[i];
        }
        
        return ans;
    }
};
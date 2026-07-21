class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l=0;int hi=0;
        while(l<s.length()&&hi<t.length()){
            if(s[l]==t[hi]){
                l++;hi++;

            }
            else{hi++;}

        }
        return l==s.length();
        
    }
};
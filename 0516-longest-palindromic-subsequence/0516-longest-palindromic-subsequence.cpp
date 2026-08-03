class Solution {
public:
    //Method-1 : Using LCS Approach(Recursion + Memoization)
    int dp[1001][1001] ;
     
    int LCS(string& s1, string& s2, int m, int n){
        //1.) handle base cases
        if(m == 0 || n == 0){
            return dp[m][n] = 0 ;
        }

        //2.) check the memoization table
        if(dp[m][n] != -1){
            return dp[m][n] ;
        }

        //3.) compare curr chars.
        if(s1[m-1] == s2[n-1]){
            return dp[m][n] = 1 + LCS(s1, s2, m-1, n-1) ;
        }

        //4.) choose max of lengths
        return dp[m][n] = max(LCS(s1,s2,m-1,n), LCS(s1,s2,m,n-1)) ;
    }
    int longestPalindromeSubseq(string s1) {
        memset(dp, -1, sizeof(dp)) ;

        //reverse the s1 and store in s2
        string s2 = s1 ;

        reverse(s2.begin() , s2.end()) ;

        int m = s1.length() ;

        return LCS(s1, s2, m, m) ;
        
    }
};
class Solution {
public:
    string removeOuterParentheses(string s) {
        int open=0;
        string result="";
        for(char c : s  ){
            
            if(c=='('){
                if(open>0){
                    result+=c;
                }
                open++;
            }else if(c==')'){
                open--;
                if(open >0){
                    result+=c;
                }
            }

        }
        return result;
        
    }
};
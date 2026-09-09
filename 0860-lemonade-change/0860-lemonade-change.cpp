class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        bool check=true;
        for(int x : bills){
            if(x==5){
                five++;
            }
            else if(x==10){
                ten++;
                if(five>0){
                    five--;
                    
                }else return false;
            }
            else if(x==20){
                if(ten>0&&five>0){
                    ten--;
                    five--;
                    
                }else if(ten==0&&five>=3){
                    five-=3;
                }else return false;
            }
        }
        return true;
    }
};
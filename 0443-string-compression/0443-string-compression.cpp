class Solution {
public:
   int compress(vector<char>& chars) {
       chars.push_back('~');
       int n=chars.size();
       int i=0;
       int j=1;
       int count=1;
       while(j<n)
       {
           if(chars[j]==chars[j-1])
           count++;
           else
           {
             chars[i]=chars[j-1];
             i++;
             if(count>=2)
             {
                 string len=to_string(count);
                 for(auto x:len)
                 {
                   chars[i]=x;
                   i++;
                 }
                 count=1;
             }
           }
           j++;
       }
       return i;
   }
};


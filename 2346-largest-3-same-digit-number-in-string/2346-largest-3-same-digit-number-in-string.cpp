class Solution {
public:
    string largestGoodInteger(string num) {
       
       for(char i = '9' ; i>='0' ; i--)
       {  int cnt = 0 ;
         for(int j = 0 ; j<num.size() ; j++)
         {    
            if(num[j] == i)
            {
                cnt++ ;
                if(cnt == 3)return string(3,i);
            }
            else cnt = 0 ;
         }
       }
       return "" ;
    }
};
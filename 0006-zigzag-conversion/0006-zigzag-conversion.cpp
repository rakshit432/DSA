class Solution {
public:
    string convert(string s, int numRows) {
        
        int n = s.size();
        if(n == 1)return s ;
        if(numRows == 1)return s ;
        vector<string>str(numRows,"");

         int index = 0 ;
         int i = 0 ;
         int j = 0 ;

         while(index < n)
         {
            while(index<s.length() && i<numRows)
            {
                str[i].push_back(s[index++]);
                i++ ;
            }

            i-=2 ;
            j++ ;

            while(index<s.length() && i>=0)
            {
                str[i].push_back(s[index++]);
                i-- ;
                j++ ;
            }

            i = 1 ;
            j-- ;
         }

         string result = "" ;
         for(int i = 0 ; i<str.size() ; i++)
         {
            result.append(str[i]);
         }

         return result ;
    }
};
class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int currcnt = 1 ;
        int n = s.size();
        int prevcnt = 0 ; 
        int ans = 0 ;

        
        for(int i = 1 ; i<n ; i++)
        {
           if(s[i] == s[i-1])
           {
            currcnt++ ;
           }

           else
           {
            ans+=min(prevcnt , currcnt);
            prevcnt = currcnt ;
            currcnt =  1 ;
           }
        }
        ans+=min(prevcnt,currcnt);
        return ans ;
    }
};
class Solution {
public:
    int longestBalanced(string s) {
        
        int maxsize = 0; 
        int n = s.size();
        int maxlen  = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
           unordered_map<char,int> mpp;
           int maxfreq = 0 ;

           
           for(int j = i ; j < n ; j++)
           {
             mpp[s[j]]++;
             maxfreq = max(maxfreq,mpp[s[j]]);
             int len = mpp.size();

             if(len*maxfreq == j-i+1)
             {
                maxlen = max(maxlen,j-i+1);
             }
           }
        
         
           
        }
        return maxlen;
    }
};

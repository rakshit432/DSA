class Solution {
public:
    int countTriples(int n) {
        
        vector<int>arr(n) ;
        for(int i = 1 ; i<=n ; i++)
        {
           arr[i-1] = i*i ;
        }
        
        unordered_set<int>st(arr.begin(),arr.end());
        int cnt = 0 ;
        for(int i = 1 ; i<n ; i++)
        {
           for(int j = i ; j>=0 ; j--)
           {
             int x = arr[i] - arr[j] ;
             if(st.find(x) != st.end())
             cnt++ ;
           }
        }      
        return cnt ;
    }
};
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n = A.size();
        unordered_map<int,int>mpp1;
        vector<int>ans(n,0);
        int res = 0;
        
        for(int i = 0 ; i<n; i++)
        {  
            res = 0 ;
            mpp1[A[i]]++ ;
            
        
        for(auto it:mpp1)
            {
            int req_freq = it.second;
            int num = it.first ;
            int cnt = 0 ;
            for(int j = 0 ; j<=i ; j++)
            {
              if(B[j] == num)cnt++ ;
            }

            if(cnt == req_freq)res++  ;
            
            }
         ans[i] = res ;
        }

        return ans;
    }
};
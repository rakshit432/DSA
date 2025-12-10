class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        
       int mod = 1e9+7 ;
        int n = complexity.size();
        int  cnt = 0 ;

        int mini = *min_element(complexity.begin(),complexity.end());
        if(complexity[0] != mini)return 0;

        for(auto &i:complexity)
        {
            if(i == mini)cnt++ ;
        }
        
        long long ans = 1;
        if(cnt>1)return 0 ;
        
        else
        {   
            for(int i = 1 ; i<n ; i++)
            {
                ans = (ans*i)%mod ;
            }
        }
        return (long long)ans ;

        
        

    }
};
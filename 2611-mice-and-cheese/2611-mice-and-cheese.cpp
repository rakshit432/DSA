class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        
        int n = reward1.size();
        int ans = 0 ;
        
        vector<pair<int,int>>res(n) ;
        for(int i = 0 ; i<n ; i++)
        {
            res[i] = {reward1[i]-reward2[i],i};
        }

        
        sort(res.rbegin(),res.rend());
        for(int i = 0 ; i<n ; i++)
        {
            if(k>0)
            {
                ans+=reward1[res[i].second];
                k-- ;
            }

            else 
            {
                ans+=reward2[res[i].second];
            }
        }

        return ans ;
    }
};
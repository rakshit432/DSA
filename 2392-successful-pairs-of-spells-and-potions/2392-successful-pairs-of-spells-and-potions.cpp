class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(),potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int>ans(n) ;

        for(int i = 0 ; i<n ; i++)
        {
            long long x = ceil((double)success / spells[i]);
            auto ind = lower_bound(potions.begin(),potions.end(),x)-potions.begin();
            int len = (m-ind);
            ans[i] = len ;
        }

        return ans ;
    }
};
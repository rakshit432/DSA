class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.begin(),cost.end());
        int sum = accumulate(cost.begin(),cost.end(),0);
        int n = cost.size() ;
        
        if(n <= 2)return sum ;
        for(int i = n-3 ; i>=0  ; i-=3)
        {
            sum-=cost[i] ;
        }
        return sum ;
    }
};
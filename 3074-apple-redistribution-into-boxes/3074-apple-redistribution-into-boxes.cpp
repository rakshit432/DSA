class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        int m = capacity.size();
        int n = apple.size();

        sort(capacity.rbegin(),capacity.rend());
        int tot = accumulate(apple.begin(),apple.end(),0);
       for(int i = 0 ; i < m ; i++)
       {
         tot-=(capacity[i]);
         if(tot<=0)return (i+1);
       }

       return m ;
    }
};
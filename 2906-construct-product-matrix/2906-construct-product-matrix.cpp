class Solution {
public:

int mod = 12345 ;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int>nums ;

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
              nums.push_back(grid[i][j]%mod);
            }
        }
        
        int size = nums.size() ;

        vector<int>pre(size,1),suff(size,1);
        
        for(int i = 1 ;i<size ; i++)
        {
          pre[i] = (1LL*pre[i-1]*nums[i-1])%mod ;
        }

        for(int i = size-2 ; i>=0 ; i--)
        {
            suff[i] = (1LL*suff[i+1]*nums[i+1])%mod ;
        }

        int k = 0 ;

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                grid[i][j] = (pre[k]*suff[k])%mod ;
                k++;
            }
        }

        return grid ;

    }
};
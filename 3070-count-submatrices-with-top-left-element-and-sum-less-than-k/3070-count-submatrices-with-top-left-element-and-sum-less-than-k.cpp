class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 1 ; j<m ; j++)
            {
               grid[i][j] += grid[i][j-1];
            }
        }
        
        int ans = 0;

        for(int j = 0; j < m; j++) {
            if(grid[0][j] <= k) ans++;
        }

        // Column-wise + count
        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 1 ; j<n; j++)
            {
                grid[j][i] += grid[j-1][i];
                if(grid[j][i] <= k)
                    ans++;
            }
        }

        return ans;
    }
};
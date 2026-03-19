class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<pair<int,int>>> ans(n,vector<pair<int,int>>(m,{0,0}));

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            { 
              if(grid[i][j] == 'X')
              {
                ans[i][j].first++ ;
              }
              else if(grid[i][j] == 'Y')
              {
                ans[i][j].second++ ;
              }
            }
        }

        // row prefix
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 1 ; j<m ; j++)
            {
              ans[i][j].first += ans[i][j-1].first;
              ans[i][j].second += ans[i][j-1].second;
            }
        }
        
        int finalans = 0;

        // first row check
        for(int j = 0; j < m; j++) {
            if(ans[0][j].first == ans[0][j].second && ans[0][j].first > 0)
                finalans++;
        }

        // column prefix + check
        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 1 ; j<n; j++)
            {
                ans[j][i].first += ans[j-1][i].first;
                ans[j][i].second += ans[j-1][i].second;

                if(ans[j][i].first == ans[j][i].second && ans[j][i].first > 0)
                    finalans++;
            }
        }

        return finalans;
    }
};
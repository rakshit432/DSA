class Solution {
public:

    void dfs(int i, int j, vector<vector<int>>& vis,
             vector<vector<char>>& grid)
    {
        vis[i][j] = 1;

        int dx[4] = {0, 1, -1, 0};
        int dy[4] = {1, 0, 0, -1};

        for(int k = 0; k < 4; k++)
        {
            int nr = i + dx[k];
            int nc = j + dy[k];

            if(nr >= 0 && nr < grid.size() &&
               nc >= 0 && nc < grid[0].size() &&
               grid[nr][nc] == '1' &&
               !vis[nr][nc])
            {
                dfs(nr, nc, vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int count = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    count++;
                    dfs(i, j, vis, grid);
                }
            }
        }

        return count;
    }
};
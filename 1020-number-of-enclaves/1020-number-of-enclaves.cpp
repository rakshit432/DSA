class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }

    void bfs(int sr, int sc, vector<vector<int>>& grid,
             vector<vector<bool>>& vis, int n, int m)
    {
        queue<pair<int,int>> q;
        q.push({sr, sc});
        vis[sr][sc] = true;

        int dr[4] = {0, 1, -1, 0};
        int dc[4] = {1, 0, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (isValid(nr, nc, n, m) &&
                    !vis[nr][nc] && grid[nr][nc] == 1)
                {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // BFS from boundary land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n-1 || j == 0 || j == m-1) &&
                    grid[i][j] == 1 && !vis[i][j])
                {
                    bfs(i, j, grid, vis, n, m);
                }
            }
        }

        // Count enclaves
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

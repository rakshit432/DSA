class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }

    void bfs(int sr, int sc, vector<vector<int>>& image,
             vector<vector<bool>>& vis, int newColor,
             int startColor, int n, int m)
    {
        queue<pair<int,int>> q;
        q.push({sr, sc});
        vis[sr][sc] = true;
        image[sr][sc] = newColor;

        int dr[4] = {0, 1, -1, 0};
        int dc[4] = {1, 0, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (isValid(nr, nc, n, m) &&
                    !vis[nr][nc] &&
                    image[nr][nc] == startColor)
                {
                    vis[nr][nc] = true;
                    image[nr][nc] = newColor;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image[0].size();

        int startColor = image[sr][sc];
        if (startColor == newColor) return image;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        bfs(sr, sc, image, vis, newColor, startColor, n, m);

        return image;
    }
};

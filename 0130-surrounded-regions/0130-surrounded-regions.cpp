class Solution {
public:

    void dfs(vector<vector<int>>& vis, vector<vector<char>>& board, int r, int c)
    {
        vis[r][c] = 1;

        int dx[4] = {0, 1, -1, 0};
        int dy[4] = {1, 0, 0, -1};

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr >= 0 && nc >= 0 &&
               nr < board.size() && nc < board[0].size() &&
               board[nr][nc] == 'O' && !vis[nr][nc])
            {
                dfs(vis, board, nr, nc);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) &&
                   board[i][j] == 'O' && !vis[i][j])
                {
                    dfs(vis, board, i, j);
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O' && !vis[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // 3D DP: dp[row][col1][col2] = max cherries from (row, col1) and (row, col2)
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        return helper(grid, 0, 0, cols - 1, dp);
    }
    
    int helper(vector<vector<int>>& grid, int row, int col1, int col2, vector<vector<vector<int>>>& dp) {
        int rows = grid.size(), cols = grid[0].size();
        // Out of bounds
        if (col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols) return 0;
        // Last row
        if (row == rows) return 0;
        // Memoization
        if (dp[row][col1][col2] != -1) return dp[row][col1][col2];
        
        int result = 0;
        // Pick cherries from both robots, if same cell, only count once
        result += (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];
        
        int maxCherries = 0;
        // Try all 9 combinations for next move
        for (int d1 = -1; d1 <= 1; ++d1) {
            for (int d2 = -1; d2 <= 1; ++d2) {
                maxCherries = max(maxCherries, helper(grid, row + 1, col1 + d1, col2 + d2, dp));
            }
        }
        result += maxCherries;
        dp[row][col1][col2] = result;
        return result;
    }
};


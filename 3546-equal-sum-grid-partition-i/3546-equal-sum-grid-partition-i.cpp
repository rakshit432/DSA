class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        // -------- ROW CHECK --------
        long long total = 0;

        // total sum
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                total += grid[i][j];
            }
        }

        long long curr = 0;

        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < m; j++) {
                curr += grid[i][j];
            }

            if(2 * curr == total)
                return true;
        }

        // -------- COLUMN CHECK --------
        total = 0;

        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                total += grid[i][j];
            }
        }

        curr = 0;

        for(int j = 0; j < m - 1; j++) {
            for(int i = 0; i < n; i++) {
                curr += grid[i][j];
            }

            if(2 * curr == total)
                return true;
        }

        return false;
    }
};
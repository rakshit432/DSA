class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> rows(n, 0), cols(m, 0);

        // Row sums
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                rows[i] += grid[i][j];
            }
        }

        // Column sums
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                cols[j] += grid[i][j];
            }
        }

        // Prefix row
        vector<long long> pre_row(n);
        pre_row[0] = rows[0];
        for(int i = 1; i < n; i++) {
            pre_row[i] = pre_row[i-1] + rows[i];
        }

        long long total_row = pre_row[n-1];

        for(int i = 1; i < n; i++) {
            if(2LL * pre_row[i-1] == total_row)
                return true;
        }

        // Prefix col
        vector<long long> pre_col(m);
        pre_col[0] = cols[0];
        for(int j = 1; j < m; j++) {
            pre_col[j] = pre_col[j-1] + cols[j];
        }

        long long total_col = pre_col[m-1];

        for(int j = 1; j < m; j++) {
            if(2LL * pre_col[j-1] == total_col)
                return true;
        }

        return false;
    }
};
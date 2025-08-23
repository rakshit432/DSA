class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int top = INT_MAX;
        int bottom = 0;
        int left = INT_MAX;
        int right = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)

                {
                    top = min(i, top);
                    bottom = max(i, bottom);
                    left = min(j, left);
                    right = max(j, right);
                }
            }
        }

      return (bottom - top + 1)*(right-left+1);
    }
};
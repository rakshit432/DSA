class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // heights[j] = consecutive 1s column height up to current row
        vector<int> heights(m, 0);
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) heights[j] = 0;
                else heights[j] += 1;
            }
            
            // For each cell, expand leftwards to count rectangles
            for (int j = 0; j < m; j++) {
                int min_h = heights[j];
                for (int k = j; k >= 0 && min_h > 0; k--) {
                    min_h = min(min_h, heights[k]);
                    res += min_h;
                }
            }
        }
        return res;
    }
};

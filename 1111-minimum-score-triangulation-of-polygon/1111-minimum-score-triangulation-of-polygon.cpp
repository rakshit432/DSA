class Solution {
public:
    int func(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
        // base case: fewer than 3 vertices → no triangle
        if (j - i < 2) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int sum = values[i] * values[k] * values[j] 
                    + func(values, i, k, dp) 
                    + func(values, k, j, dp);
            mini = min(mini, sum);
        }

        return dp[i][j] = mini;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return func(values, 0, n - 1, dp);
    }
};

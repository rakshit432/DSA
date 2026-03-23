class Solution {
public:
    int mod = 1e9 + 7;

    pair<long long,long long> func(vector<vector<int>>& grid, int r, int c,
                                  vector<vector<pair<long long,long long>>>& dp)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(r == n-1 && c == m-1){
            return {grid[r][c], grid[r][c]};
        }

        if(dp[r][c].first != LLONG_MIN) return dp[r][c];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        
        if(r+1 < n){
            auto down = func(grid, r+1, c, dp);

            long long a = down.first * grid[r][c];
            long long b = down.second * grid[r][c];

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

       
        if(c+1 < m){
            auto right = func(grid, r, c+1, dp);

            long long a = right.first * grid[r][c];
            long long b = right.second * grid[r][c];

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        return dp[r][c] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<pair<long long,long long>>> dp(
            n, vector<pair<long long,long long>>(m, {LLONG_MIN, LLONG_MIN})
        );

        auto res = func(grid, 0, 0, dp);

        long long ans = res.first;

        if(ans < 0) return -1;
        return ans % mod;
    }
};
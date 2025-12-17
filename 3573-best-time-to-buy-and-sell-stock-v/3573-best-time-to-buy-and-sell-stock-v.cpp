class Solution {
public:
    long long memo[1001][501][3];

    long long dfs(int day, int pos, int rem, int totalDays, vector<int>& val) {
        if ((rem == 0 || day == totalDays) && pos == 0) return 0;
        if ((rem == 0 || day == totalDays) && pos != 0) return -(1e18);

        if (memo[day][rem][pos] != -1)
            return memo[day][rem][pos];

        long long res;

        if (pos == 0) {
            long long a = dfs(day + 1, 0, rem, totalDays, val);
            long long b = -val[day] + dfs(day + 1, 1, rem, totalDays, val);
            long long c =  val[day] + dfs(day + 1, 2, rem, totalDays, val);
            res = max({a, b, c});
        }
        else if (pos == 1) {
            long long a = dfs(day + 1, 1, rem, totalDays, val);
            long long b =  val[day] + dfs(day + 1, 0, rem - 1, totalDays, val);
            res = max(a, b);
        }
        else {
            long long a = dfs(day + 1, 2, rem, totalDays, val);
            long long b = -val[day] + dfs(day + 1, 0, rem - 1, totalDays, val);
            res = max(a, b);
        }

        return memo[day][rem][pos] = res;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        memset(memo, -1, sizeof(memo));
        int n = prices.size();
        return dfs(0, 0, k, n, prices);
    }
};

class Solution {
public:

    bool check(vector<int>& arr, int n, int ind, vector<int>& dp, vector<bool>& visiting)
    {
        if(ind >= n || ind < 0) return false;
        if(arr[ind] == 0) return true;
        if(dp[ind] != -1) return dp[ind];
        if(visiting[ind]) return false;

        visiting[ind] = true;
        dp[ind] = check(arr, n, ind + arr[ind], dp, visiting) ||
                  check(arr, n, ind - arr[ind], dp, visiting);
        return dp[ind];
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> dp(n, -1);
        vector<bool> visiting(n, false);

        return check(arr, n, start, dp, visiting);
    }
};
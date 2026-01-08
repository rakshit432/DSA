class Solution {
public:
    int dp[501][501];

    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if (i == nums1.size() || j == nums2.size())
            return INT_MIN;  // prevent empty subsequence

        if (dp[i][j] != -1)
            return dp[i][j];

        int take = nums1[i] * nums2[j];
        int next = solve(i + 1, j + 1, nums1, nums2);
        if (next > 0) take += next;

        int skip1 = solve(i + 1, j, nums1, nums2);
        int skip2 = solve(i, j + 1, nums1, nums2);

        return dp[i][j] = max({take, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums1, nums2);
    }
};

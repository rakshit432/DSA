class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());

        int mini = n - 1;

        for (int i = 0; i < n; i++) {
            long long db = 1LL * nums2[i] * k;

            int r = upper_bound(nums2.begin(), nums2.end(), db) - nums2.begin() - 1;

            if (r >= i) {
                int window = r - i + 1;
                mini = min(mini, n - window);
            }
        }

        return mini;
    }
};

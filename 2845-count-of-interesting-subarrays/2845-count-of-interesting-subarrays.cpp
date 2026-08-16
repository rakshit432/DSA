class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        
        int n = nums.size();
        vector<int> dp(n, 0);

        for(int i = 0; i < n; i++) {
            nums[i] = nums[i] % modulo;
        }

        // dp[i] = count of elements satisfying nums[j] % modulo == k
        // from 0 to i
        for(int i = 0; i < n; i++) {
            if(nums[i] == k) {
                dp[i] = 1;
            }

            if(i > 0) {
                dp[i] += dp[i - 1];
            }
        }

        long long ans = 0;

        // prefix count before starting
        unordered_map<int, long long> mpp;
        mpp[0] = 1;

        for(int i = 0; i < n; i++) {

            int rem = dp[i] % modulo;

            // Need:
            // (dp[i] - previous) % modulo == k
            int required = (rem - k + modulo) % modulo;

            ans += mpp[required];

            mpp[rem]++;
        }

        return ans;
    }
};
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // Step 1: Count frequencies
        unordered_map<int, long long> freq;
        for (int p : power) freq[p]++;

        // Step 2: Sort unique power values
        vector<int> vals;
        for (auto& it : freq) vals.push_back(it.first);
        sort(vals.begin(), vals.end());

        int n = vals.size();
        vector<long long> dp(n, 0);

        // Step 3: Tabulation
        dp[0] = vals[0] * freq[vals[0]];

        for (int i = 1; i < n; i++) {
            long long include = vals[i] * freq[vals[i]];
            int j = i - 1;

            // Find last index j that is not within ±2 range
            while (j >= 0 && abs(vals[i] - vals[j]) <= 2) j--;

            if (j >= 0) include += dp[j];
            long long exclude = dp[i - 1];

            dp[i] = max(include, exclude);
        }

        return dp[n - 1];
    }
};

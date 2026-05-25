class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        vector<int> dp(n, 0);

        dp[0] = 1;

        for(int i = 1; i < n; i++)
        {
            if(s[i] == '1')
            continue;

            for(int prev = max(0, i - maxJump);
                prev <= i - minJump;
                prev++)
            {
                if(dp[prev])
                {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n-1];
    }
};
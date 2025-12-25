class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        sort(happiness.rbegin(), happiness.rend());

        int n = happiness.size();
        int i = 0;
        long long ans = 0;
        while (i < k) {
            if (happiness[i] - i >= 0) {
                ans += (happiness[i] - i);
                i++;
            }
            else break ;
        }

        return ans;
    }
};
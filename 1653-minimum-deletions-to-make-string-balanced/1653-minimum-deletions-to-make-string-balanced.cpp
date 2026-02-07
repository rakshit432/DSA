class Solution {
public:
    int minimumDeletions(string s) {
        int cntB = 0;
        int ans = 0;

        for (char c : s) {
            if (c == 'b') {
                cntB++;
            } else {
                ans = min(ans + 1, cntB);
            }
        }
        return ans;
    }
};

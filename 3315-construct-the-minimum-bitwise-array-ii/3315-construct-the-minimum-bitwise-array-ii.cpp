class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int p : nums) {

            if (p == 2) {          // only even prime, impossible case
                ans.push_back(-1);
                continue;
            }

            int x = p;
            int bit = 1;

            // find the first 0 bit after trailing 1s
            while (x & bit) {
                bit <<= 1;
            }

            // clear the leftmost bit of trailing 1s
            ans.push_back(p ^ (bit >> 1));
        }

        return ans;
    }
};

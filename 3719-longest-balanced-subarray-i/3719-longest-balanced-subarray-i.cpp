class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            unordered_map<int,int> odd, even;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2)
                    odd[nums[j]]++;
                else
                    even[nums[j]]++;

                if (odd.size() == even.size())
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

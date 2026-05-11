class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++)
        {
            string s = to_string(nums[i]);

            for(int j = 0; j < s.size(); j++)
            {
                int x = s[j] - '0';
                ans.push_back(x);
            }
        }

        return ans;
    }
};
class Solution {
public:
    int minElement(vector<int>& nums) {
        
        int mini = INT_MAX ;
        int n = nums.size();

        for(int i = 0 ; i<n ; i++)
        {
            string s = to_string(nums[i]);
            int sum = 0 ;
            for(char ch:s)
            {
              sum+=(ch-'0');
            }
            mini = min(mini,sum);
        }
        return mini ;
    }
};
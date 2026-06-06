class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n,0);
        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] + nums[i+1];
        }
        vector<int> ans(n);
        int psum = 0;
        for(int i=0;i<n;i++){
            ans[i] = abs(suffix[i] - psum);
            psum += nums[i];
        }
        return ans;
    }
};
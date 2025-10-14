class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int len = 1 ;
        int prev = 0;
        int n = nums.size() ;
        for(int i = 1 ; i<n ; i++)
        {
            if(nums[i] > nums[i-1])len++ ;
            else 
            {
                if(max(len/2,min(len,prev))>=k)return true ;
                prev = len ;
                len = 1 ;
            }
        }
        return max(len/2, min(len, prev))>=k;

    }
};
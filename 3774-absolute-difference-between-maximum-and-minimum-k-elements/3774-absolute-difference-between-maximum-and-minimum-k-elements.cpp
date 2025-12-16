class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
       int s1=0,s2=0;

        for(int i=0 ; i<k  ; i++)
            {
              s1+=(nums[i]);
                s2+=(nums[n-k+i]);
                  
            }
        return abs(s1-s2);
        
    }
};
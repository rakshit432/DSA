class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        set<int>s(nums1.begin(),nums1.end());

        for(auto it:nums2)
        {
            if(s.find(it) != s.end())
            {
                return it ;
            }
        }

        return -1 ;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos=nums[nums.size()-1];
        if (nums.size()==1) return true; 
        if (nums[0]==0) return false;
        int j= nums.size()-1;
        int i=nums.size()-2;
        while(i>=0){
            if (nums[i]>=j-i){
                j=i;
            }
            i--;
        }
        if (j!=0) return false;
        return true;
    }
};
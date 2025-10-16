class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
         
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                int val=nums[i]%value;
                if(val==0) mp[val]++;
                else mp[val+value]++;
            }
            else{
                mp[nums[i]%value]++;
            }
        }
        int f=0;
        while(1){
            if(mp[f%value]==0){
                return f;
            }
            else{
                mp[f%value]--;
            }
            f++;
        }
        return f;


    }
};
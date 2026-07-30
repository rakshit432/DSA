class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(),currend=0,jump=0,farthest=0;

        for(int i=0;i<n-1;i++){

           farthest=max(farthest,nums[i]+i);

           if(i==currend){
               jump++;
               currend=farthest;
           }
        }

        return jump;
    }
};
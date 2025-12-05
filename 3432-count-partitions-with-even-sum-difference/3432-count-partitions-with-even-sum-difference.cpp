class Solution {
public:
    int countPartitions(vector<int>& nums) {

      int cnt = 0 ;

      int sum = accumulate(nums.begin(),nums.end(),0);
       
       int s = 0;
      for(int i = 0 ; i<nums.size()-1 ; i++)
      {
        s+=nums[i];
        if((2*s-sum)%2 == 0)
        {
            cnt++ ;
        }
      }   

      return cnt ;
    }
};
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<long long int,long long int>left ;
        unordered_map<long long int,long long int>right ;
        long long int cnt = 0 ;
        long long int mod = 1e9+7 ;

        for(int i = 0 ; i<n ; i++)
        {
            right[nums[i]]++ ;
        }

        for(int i = 0 ; i<n ; i++)
        {
          long long int curr = nums[i] ;
          long long int req = 2*curr ;
          
          right[nums[i]]--;
          if (right[nums[i]] < 0) right[nums[i]] = 0; 
            
          if(left[req] > 0 && right[req] > 0)
          {
            cnt += (left[req]*right[req]) ;
          }
          
          left[nums[i]]++ ;
        }
        
        return cnt%mod ;
    }
};
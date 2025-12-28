class Solution {
public:
    
    int upperbound(vector<int>&nums)
    {
      int low = 0 ;
      int high = nums.size()-1 ;
      
      while(low<=high)
      {
        int mid = (low+high)/2 ;

        if(nums[mid] >= 0)
        {   
            low = mid+1 ;
        }

        else high = mid-1 ;
      }
      return low ;
    }

    int countNegatives(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m  = grid[0].size();

       int cnt = 0 ;

       for(int i = 0 ; i<n ; i++)
       {
         cnt+=(m-upperbound(grid[i]));
       }
       return cnt ;
    }
};
class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
			
            long long XOR = 0  ;
            int n = nums.size() ;

            for(int i = 0 ; i<nums.size() ; i++)
            {
                XOR ^= nums[i] ;
            }
            
            long long rightmost = (XOR & (XOR-1)) ^ XOR ;
            int XOR1 = 0 , XOR2 = 0 ;
             
            
            for(int i = 0 ; i<n ;i++ )
            {
              if(nums[i] & rightmost)
              {
                XOR1 ^= nums[i] ;
              }
              else
              XOR2  ^= nums[i] ;
            }

            if(XOR1<XOR2)return {XOR1,XOR2};
            else return {XOR2 , XOR1};

		}
};
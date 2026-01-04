class Solution
{
public:
    int trap(vector<int> &height){
        
        int leftmax = 0 , rightmax =  0 ;
        int left = 0 , n = height.size() ,right = n-1 ;
        int total = 0 ;

        while(left < right)
        {
            if(height[left] <= height[right])
            {
                if(leftmax > height[left])
                {
                    total += (leftmax-height[left]);
                }

                else leftmax = height[left];
                left = left+1 ;
            }

            else{
                if(rightmax > height[right])
                {
                    total += (rightmax - height[right]);
                }

                else rightmax = height[right];
                right = right-1 ;
            }
        }

        return total ;

    }
};
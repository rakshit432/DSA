class Solution {
public:
    int mirrorDistance(int n) {

        int m = n ;
        int digit = 0 ;
        int r = 0;
        while(m != 0)
            {  
                digit = m%10;
               r=r*10+digit;
                m/=10;              
            }
        
        return abs(n-r)  ;
    }
};
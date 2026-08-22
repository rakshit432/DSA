class Solution {
public:
    bool checkDivisibility(int n) {
        
        int sum = 0 ; 
        int res = n ;
        int product = 1 ;

        while(n!=0)
        {
            int x = n%10 ;
            sum+=x ;
            product*=x ;
            n/=10 ;
        }
         
        return (res%(sum+product) == 0);
    }
};
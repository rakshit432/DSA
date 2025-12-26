class Solution {
public:
    int bestClosingTime(string customers) {
        
      int y = 0 ;
      int n = 0 ;

       for (char c : customers) {
            if (c == 'Y') y++;
        }
       
       int mini = y ;
       int min_hr = 0 ;
       int m = customers.size() ;

       for(int i = 0 ; i<m ; i++)
       { 
         char ch = customers[i];
         if(ch == 'Y')
         {
            y-- ;
         } 
         if(ch == 'N')
         {
            n++ ;
         }

           if(mini > y+n)
           {
            mini=y+n ;
            min_hr = i+1 ;
           }
         }
         return min_hr ;
       }
    
};
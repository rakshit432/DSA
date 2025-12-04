class Solution {
public:
    int countCollisions(string directions) {

        int n = directions.size() ;
        if(n==1)return 0 ;

        int l = 0 ;
        int r = n-1 ;

        while(directions[l] == 'L')l++; 
        while(l<r && directions[r] == 'R')r-- ;

        if(l>=r)return 0 ;
        int col = 0 ;
        for( ; l<=r ; l++)
        {
            col += (directions[l]!='S') ;
        }
        return col ;
    }
};

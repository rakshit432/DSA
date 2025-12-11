class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector <int> maxrow(n+1,INT_MIN);
        vector <int> minrow(n+1,n+1);
        vector <int> maxcol(n+1,INT_MIN);
        vector <int> mincol(n+1,n+1);
        for(auto &i:buildings){
            int x=i[0];
            int y=i[1];
            maxrow[y]=max(maxrow[y],x);
            minrow[y]=min(minrow[y],x);
            maxcol[x]=max(maxcol[x],y);
            mincol[x]=min(mincol[x],y);
        }
        int cnt=0;
        for(auto &it:buildings){
            int x=it[0];
            int y=it[1];
            if(maxrow[y]>x&&minrow[y]<x&&maxcol[x]>y&&mincol[x]<y){
                cnt++;
            }
            
        }
        return cnt;
    }
};
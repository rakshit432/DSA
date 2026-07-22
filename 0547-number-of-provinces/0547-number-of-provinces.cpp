class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adjList){
        vis[node]=1;
        for(auto &it:adjList[node]){
            if(!vis[it]){
                dfs(it, vis, adjList);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<vector<int>>adjList(n);
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(i, vis, adjList);
            }
        }
        return count;
    }
};
class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++) {
            mpp[arr[i]].push_back(i);
        }

        queue<pair<int,int>> q;
        vector<int> vis(n, 0);

        q.push({0,0});
        vis[0] = 1;

        while(!q.empty()) {

            auto [idx, steps] = q.front();
            q.pop();

            if(idx == n-1) return steps;

            // i-1
            if(idx-1 >= 0 && !vis[idx-1]) {
                vis[idx-1] = 1;
                q.push({idx-1, steps+1});
            }

            // i+1
            if(idx+1 < n && !vis[idx+1]) {
                vis[idx+1] = 1;
                q.push({idx+1, steps+1});
            }

            // same value jumps
            for(auto next : mpp[arr[idx]]) {

                if(!vis[next]) {
                    vis[next] = 1;
                    q.push({next, steps+1});
                }
            }

            // IMPORTANT optimization
            mpp[arr[idx]].clear();
        }

        return -1;
    }
};
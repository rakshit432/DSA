class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }

        int mini = INT_MAX;

        for (auto &it : mpp) {
            auto &v = it.second;
            int n = v.size();

            if (n >= 3) {
                int dist = INT_MAX ;
                for(int i = 0 ;i<n  ; i++)
                {
                  if(i+2<n)
                  dist = min(dist,abs(v[i]-v[i+1])+abs(v[i]-v[i+2])+abs(v[i+1]-v[i+2]));
                }

                mini = min(mini, dist);
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};
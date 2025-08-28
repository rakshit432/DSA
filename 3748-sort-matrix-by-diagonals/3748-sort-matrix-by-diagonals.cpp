class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        unordered_map<int, vector<int>> mpp;

        int n = grid.size();
        int m = grid[0].size();

        // Step 1: Store elements by diagonals (j - i)
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                mpp[j - i].push_back(grid[i][j]);
            }
        }

        // Step 2: Sort diagonals
        for(auto &it : mpp) {
            sort(it.second.begin(), it.second.end());
            if(it.first > 0) reverse(it.second.begin(), it.second.end());
        }

        // Step 3: Put back into grid
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                grid[i][j] = mpp[j - i].back();
                mpp[j - i].pop_back();   // important: consume element
            }
        }

        return grid;
    }
};

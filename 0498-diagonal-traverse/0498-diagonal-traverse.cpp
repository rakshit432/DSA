class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;

        for (int s = 0; s <= m + n - 2; s++) {
            vector<int> temp;

            for (int i = 0; i < m; i++) {
                int j = s - i; // since i + j = s
                if (j >= 0 && j < n) {
                    temp.push_back(mat[i][j]);
                }
            }

            // Reverse on alternate diagonals
            if (s % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }

            ans.insert(ans.end(), temp.begin(), temp.end());
        }

        return ans;
    }
};

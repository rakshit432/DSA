class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();

        long long maxi = LLONG_MIN;  // to avoid overflow
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            long long diag = 1LL * dimensions[i][0] * dimensions[i][0] +
                             1LL * dimensions[i][1] * dimensions[i][1];
            int area = dimensions[i][0] * dimensions[i][1];

            if (diag > maxi) {
                maxi = diag;
                maxArea = area;
            } 
            else if (diag == maxi) {
                maxArea = max(maxArea, area);  // prefer larger area
            }
        }
        return maxArea;
    }
};

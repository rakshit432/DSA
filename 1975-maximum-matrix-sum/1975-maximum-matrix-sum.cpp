class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (auto &row : matrix) {
            for (int val : row) {
                sum += abs(val);
                if (val < 0) negCount++;
                minAbs = min(minAbs, abs(val));
            }
        }

        // If odd number of negatives, one must remain negative
        if (negCount % 2 == 1) {
            sum -= 2LL * minAbs;
        }

        return sum;
    }
};

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

private:
    // recursive helper
    bool solve(vector<double>& nums) {
        // base case
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }

        // try all pairs
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;

                // create remaining list without nums[i], nums[j]
                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                // try all operations
                for (double val : compute(nums[i], nums[j])) {
                    next.push_back(val);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    // generate all possible results from a and b
    vector<double> compute(double a, double b) {
        vector<double> res;
        res.push_back(a + b);
        res.push_back(a - b);
        res.push_back(b - a);
        res.push_back(a * b);
        if (fabs(b) > 1e-6) res.push_back(a / b);
        if (fabs(a) > 1e-6) res.push_back(b / a);
        return res;
    }
};

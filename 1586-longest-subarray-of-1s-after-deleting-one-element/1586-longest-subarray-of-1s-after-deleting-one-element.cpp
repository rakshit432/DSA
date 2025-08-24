class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;        // count of current streak of 1s
        int prevsum = 0;    // count of previous streak of 1s (before a zero)
        int maxi = 0;       // result

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                // when a zero is found, combine prev streak + current streak
                maxi = max(maxi, prevsum + sum);
                prevsum = sum;  // move current streak to prev
                sum = 0;        // reset current streak
            } else {
                sum++;          // extend current streak of 1s
            }
        }

        // Edge case: if last streak reaches the end, we still need to check
        maxi = max(maxi, prevsum + sum);

        // subtract 1 because we must delete one element
        return maxi == n ? maxi - 1 : maxi;
    }
};

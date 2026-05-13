class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        // Difference array
        vector<int> diff(2 * limit + 2, 0);

        int l = 0;
        int r = n - 1;

        while(l < r)
        {
            int a = nums[l];
            int b = nums[r];

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;

            int sum = a + b;

            /*
                For every target sum:

                outside [low, high] -> 2 moves
                inside [low, high]  -> 1 move
                exact sum           -> 0 move
            */

            // Initially assume 2 moves
            diff[2] += 2;

            // From low onwards -> reduce by 1
            diff[low] -= 1;

            // Exact sum -> reduce another 1
            diff[sum] -= 1;

            // After exact sum -> back to 1 move
            diff[sum + 1] += 1;

            // After high -> back to 2 moves
            diff[high + 1] += 1;

            l++;
            r--;
        }

        int ans = INT_MAX;

        int cur = 0;

        // Try every possible target sum
        for(int s = 2; s <= 2 * limit; s++)
        {
            cur += diff[s];

            ans = min(ans, cur);
        }

        return ans;
    }
};
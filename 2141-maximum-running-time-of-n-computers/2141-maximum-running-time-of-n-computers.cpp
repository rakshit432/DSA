class Solution {
public:

    bool canRun(long long t, int n, const vector<int>& batteries) {
        long long energy = 0;
        for (long long b : batteries) {
            energy += min(b, t);
        }
        return energy >= t * n;
    }

    long long maxRunTime(int n, vector<int>& batteries) {

        long long total = 0;
        for (int b : batteries) total += b;

        long long low = 0, high = total / n;

        while (low < high) {
            long long mid = (low + high + 1) / 2;

            if (canRun(mid, n, batteries))
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }
};

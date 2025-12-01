class Solution {
public:
    
    bool possible(long long t, vector<int>& batteries, int n) {
        long long sum = 0;
        for (int b : batteries)
            sum += min((long long)b, t);
        
        return sum >= t * n;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long total = 0;
        for (int b : batteries)
            total += b;

        long long l = 0, h = total / n;

        while (l < h) {
            long long m = (l + h + 1) / 2;   // IMPORTANT

            if (possible(m, batteries, n))
                l = m;
            else
                h = m - 1;
        }

        return l;
    }
};

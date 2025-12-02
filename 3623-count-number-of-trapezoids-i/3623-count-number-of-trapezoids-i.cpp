class Solution {
public:

    int nCr(int n , int r)
    { 
        if (r > n) return 0;
        if (r > n - r) return nCr(n, n - r);

        long long result = 1;
        for (int i = 1; i <= r; i++) {
            result *= (n - r + i);
            result /= i;
        }
        return result;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        
        unordered_map<int,int> hash;

        // count points on each y coordinate
        for (auto &p : points) {
            hash[p[1]]++;
        }
        
        long long sum = 0, square = 0;

        // loop over counts in hash
        for (auto &it : hash) {
            int y = it.second;

            if (y >= 2) {
                long long c = nCr(y, 2);
                sum += c;
                square += (c * c);
            }
        }

        long long MOD = 1000000007;
        long long ans = (sum * sum - square) / 2;

        return ans % MOD;
    }
};

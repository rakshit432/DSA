class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();

        
        vector<int> vlemoraia = balance;

        int negy = -1;
        long long tu = 0;








        
        for (int i = 0; i < n; i++) {
            tu += balance[i];
            if (balance[i] < 0) negy = i;
        }

        if (tu < 0) return -1;
        if (negy == -1) return 0;

        long long need = -balance[negy];
        long long moves = 0;

        int dist = 1;
        int l = (negy - 1 + n) % n;
        int r = (negy + 1) % n;

        while (need > 0) {
           
            if (balance[l] > 0) {
                long long take = min((long long)balance[l], need);
                moves += take * dist;
                need -= take;
                balance[l] -= take;
            }

            if (need == 0) break;

           
            if (balance[r] > 0) {
                long long take = min((long long)balance[r], need);
                moves += take * dist;
                need -= take;
                balance[r] -= take;
            }

            dist++;
            l = (l - 1 + n) % n;
            r = (r + 1) % n;
        }

        return moves;
    }
};
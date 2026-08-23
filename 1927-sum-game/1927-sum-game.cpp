class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int cnt = 0, cnt1 = 0;
        int s1 = 0, s2 = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                cnt++;
            else
                s1 += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                cnt1++;
            else
                s2 += num[i] - '0';
        }

       
        return 2 * (s1 - s2) != 9 * (cnt1 - cnt);
    }
};
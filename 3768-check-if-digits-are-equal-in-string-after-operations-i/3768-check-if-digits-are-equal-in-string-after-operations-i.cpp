class Solution {
public:
    bool hasSameDigits(string s) {
        int numOp = s.size() - 2;

        for (int i = 0; i < numOp; i++) {
            string str = "";
            for (int j = 1; j < s.size(); j++) {
                int sum = ((s[j] - '0') + (s[j - 1] - '0')) % 10;
                str.push_back(sum + '0');
            }
            s = str;
        }

        return (s[0] == s[1]);
    }
};

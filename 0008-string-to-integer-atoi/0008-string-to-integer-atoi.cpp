class Solution {
public:

    int func(string &s, int i, long long num, int sign) {
        if (i >= s.size() || !isdigit(s[i])) {
            return (int)(sign * num);
        }

        int digit = s[i] - '0';

        // ✅ Check overflow BEFORE updating num
        if (num > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        num = num * 10 + digit;

        return func(s, i + 1, num, sign);
    }

    int myAtoi(string s) {
        int i = 0;

        // skip spaces
        while (i < s.size() && s[i] == ' ') i++;

        int sign = 1;

        // sign check
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return func(s, i, 0, sign);
    }
};
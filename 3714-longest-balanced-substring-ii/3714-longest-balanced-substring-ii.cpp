class Solution {
public:

    int singleChar(string &s) {
        int maxLen = 1, count = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i-1]) count++;
            else {
                maxLen = max(maxLen, count);
                count = 1;
            }
        }
        return max(maxLen, count);
    }

    int helper(string &s, char ch1, char ch2) {
        unordered_map<int,int> mp;
        mp[0] = -1;

        int c1 = 0, c2 = 0;
        int maxLen = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] != ch1 && s[i] != ch2) {
                mp.clear();
                mp[0] = i;
                c1 = c2 = 0;
                continue;
            }

            if(s[i] == ch1) c1++;
            else c2++;

            int diff = c1 - c2;

            if(mp.count(diff))
                maxLen = max(maxLen, i - mp[diff]);
            else
                mp[diff] = i;
        }

        return maxLen;
    }

    int longestBalanced(string s) {

        int ans = singleChar(s);

        ans = max(ans, helper(s,'a','b'));
        ans = max(ans, helper(s,'a','c'));
        ans = max(ans, helper(s,'b','c'));

        // three character case
        unordered_map<long long,int> mp;
        mp[0] = -1;

        int a = 0, b = 0, c = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;

            long long key = ((long long)(a-b) << 32) | (unsigned int)(a-c);

            if(mp.count(key))
                ans = max(ans, i - mp[key]);
            else
                mp[key] = i;
        }

        return ans;
    }
};

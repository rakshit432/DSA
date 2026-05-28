class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxLen = 0;
        unordered_map<char, int> freq;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;

            int maxi = 0;
            for (auto &it : freq) {
                maxi = max(maxi, it.second);
            }

            if ((right - left + 1) - maxi <= k) {
                maxLen = max(maxLen, right - left + 1);
            } else {
                freq[s[left]]--;
                left++;
            }
        }

        return maxLen;
    }
};
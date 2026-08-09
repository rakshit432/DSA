class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        unordered_map<char, int> mpp1;

        for (auto i : s1) {
            mpp1[i]++;
        }

        int l = 0;
        int r = s1.size() - 1;
        int n = s2.size();

        if (s1.size() > s2.size())
            return false;

        while (r < n) {

            unordered_map<char, int> mpp2;

            // Count characters in current window
            int temp = l;
            while (temp <= r) {
                mpp2[s2[temp]]++;
                temp++;
            }

            // Check if both frequency maps are equal
            if (mpp1 == mpp2)
                return true;

            l++;
            r++;
        }

        return false;
    }
};
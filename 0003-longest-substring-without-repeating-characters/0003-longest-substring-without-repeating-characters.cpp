class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        set<int> st;
        int ans=0;
        while(r<s.size()){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
            ans=max(ans,r-l);
        }
        return ans;
    }
};
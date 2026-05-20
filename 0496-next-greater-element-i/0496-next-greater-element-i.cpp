class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        stack<int> st;
        vector<int> arr;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; i--) {
            
                while (!st.empty() && st.top() <= nums2[i]) {
                    st.pop();
                }
                if(st.empty()){
                    mpp[nums2[i]] = -1;
                   
                }
                else{
                    mpp[nums2[i]] = st.top();
                    
                }
                st.push(nums2[i]);
            
        }
        for(int x: nums1){
            arr.push_back(mpp[x]);
        }
        return arr;
    }
};
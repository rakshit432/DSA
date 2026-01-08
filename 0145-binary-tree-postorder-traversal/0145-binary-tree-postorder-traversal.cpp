class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        stack<TreeNode*> st;
        TreeNode* prev = nullptr;

        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }

            TreeNode* curr = st.top();

            if (!curr->right || curr->right == prev) {
                ans.push_back(curr->val);
                st.pop();
                prev = curr;
                root = nullptr;
            } else {
                root = curr->right;
            }
        }
        return ans;
    }
};

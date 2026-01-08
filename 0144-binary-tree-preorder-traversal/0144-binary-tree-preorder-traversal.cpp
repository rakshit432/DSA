class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

    void preorder(TreeNode* node, vector<int>& ans) {
        if (!node) return;
        ans.push_back(node->val);      // Root
        preorder(node->left, ans);     // Left
        preorder(node->right, ans);    // Right
    }
};

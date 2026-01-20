/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inmap;
        for (int i = 0; i < inorder.size(); i++)
            inmap[inorder[i]] = i;

        return helper(inorder, postorder,
                      0, postorder.size() - 1,
                      0, inorder.size() - 1,
                      inmap);
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,
                     int pst, int pend,
                     int inst, int inend,
                     unordered_map<int,int>& inmap) {

        if (pst > pend || inst > inend) return nullptr;

        TreeNode* root = new TreeNode(postorder[pend]);

        int inroot = inmap[root->val];
        int leftSize = inroot - inst;

        root->left = helper(inorder, postorder,
                            pst, pst + leftSize - 1,
                            inst, inroot - 1,
                            inmap);

        root->right = helper(inorder, postorder,
                             pst + leftSize, pend - 1,
                             inroot + 1, inend,
                             inmap);

        return root;
    }
};

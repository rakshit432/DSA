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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inmap;
        for(int i = 0; i < inorder.size(); i++)
            inmap[inorder[i]] = i;

        return helper(preorder, 0, preorder.size() - 1,
                      inorder, 0, inorder.size() - 1,
                      inmap);
    }

    TreeNode* helper(vector<int>& preorder, int prest, int prend,
                     vector<int>& inorder, int inst, int inend,
                     unordered_map<int,int>& inmap) {

        if (prest > prend || inst > inend) return nullptr;

        TreeNode* root = new TreeNode(preorder[prest]);
        int inroot = inmap[root->val];
        int numleft = inroot - inst;

        root->left = helper(preorder, prest + 1, prest + numleft,
                             inorder, inst, inroot - 1, inmap);

        root->right = helper(preorder, prest + numleft + 1, prend,
                              inorder, inroot + 1, inend, inmap);

        return root;
    }
};

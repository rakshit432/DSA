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

int result = -1 ;
int k ;
void inorder(TreeNode* node)
    {
        if(node == nullptr || k == 0)
            return;

        inorder(node->left);

        if(--k == 0)
        {
            result = node->val;
            return;
        }

        inorder(node->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        inorder(root) ;
        return result;
    }
};
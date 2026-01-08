class Solution {
public:
    long long totalSum = 0;

    int maxProduct(TreeNode* root) {
        long long maxi = 0;
        totalSum = func(root, maxi);  
        func(root, maxi);              
        return maxi % 1000000007;
    }

    long long func(TreeNode* root, long long &maxi) {
        if (root == nullptr)
            return 0;

        long long lt = func(root->left, maxi);
        long long rt = func(root->right, maxi);

        long long subSum = root->val + lt + rt;

       
        maxi = max(maxi, subSum * (totalSum - subSum));

        return subSum;
    }
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        int answer = 0;
        int maxi = INT_MIN;

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            level++;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (sum > maxi) {
                maxi = sum;
                answer = level;
            }
        }

        return answer;
    }
};

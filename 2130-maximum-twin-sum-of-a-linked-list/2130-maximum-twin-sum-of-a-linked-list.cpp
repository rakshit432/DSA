/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>ans;

        ListNode* temp = head ;
        while(temp != NULL)
            {
                int x = temp->val ;
                temp = temp->next;
                ans.push_back(x);
            }

        int s = 0;
        int e = (int)ans.size()-1 ;

        int maxi = INT_MIN ;
        while(s < e)
            {
                int sum = ans[s]+ans[e];
                maxi = max(maxi,sum);
                s++;
                e--;
            }

        return maxi ;
    }
};
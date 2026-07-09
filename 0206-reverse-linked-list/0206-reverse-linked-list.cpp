class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize pointers
        ListNode* prev = nullptr; // Previous node starts as NULL
        ListNode* next = nullptr; // Next node
        ListNode* curr = head;    // Current node starts at the head

        
        while (curr != nullptr) {
            next = curr->next;

            curr->next = prev;

          
            prev = curr; 
            curr = next; 
        }

        return prev;
    }
};
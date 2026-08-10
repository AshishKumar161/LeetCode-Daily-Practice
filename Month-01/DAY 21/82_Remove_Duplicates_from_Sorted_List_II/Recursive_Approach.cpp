class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Duplicate found
        if (head->val == head->next->val) {

            int duplicate = head->val;

            // Skip all nodes with duplicate value
            while (head != NULL && head->val == duplicate) {
                head = head->next;
            }

            return deleteDuplicates(head);
        }

        // Current node is unique
        head->next = deleteDuplicates(head->next);

        return head;
    }
};
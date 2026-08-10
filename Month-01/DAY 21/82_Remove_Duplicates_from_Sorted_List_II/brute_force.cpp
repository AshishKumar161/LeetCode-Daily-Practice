class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr != NULL) {

            ListNode* temp = curr->next;
            bool duplicate = false;

            while (temp != NULL) {

                if (temp->val == curr->val) {
                    duplicate = true;
                    break;
                }

                temp = temp->next;
            }

            if (duplicate) {
                int value = curr->val;

                while (curr != NULL && curr->val == value) {
                    curr = curr->next;
                }

                prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};
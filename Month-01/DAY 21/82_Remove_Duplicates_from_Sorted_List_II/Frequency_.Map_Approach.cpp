class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == NULL) {
            return NULL;
        }

        unordered_map<int, int> freq;

        ListNode* curr = head;

        // Count frequencies
        while (curr != NULL) {
            freq[curr->val]++;
            curr = curr->next;
        }

        // Dummy node
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        curr = head;

        // Remove nodes whose frequency > 1
        while (curr != NULL) {

            if (freq[curr->val] > 1) {
                prev->next = curr->next;
            }
            else {
                prev = curr;
            }

            curr = curr->next;
        }

        return dummy.next;
    }
};
class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {
    
            if (head == nullptr || head->next == nullptr) {
                return nullptr;
            }
    
            ListNode* temp = head;
            int count = 0;
    
            while (temp != nullptr) {
                count++;
                temp = temp->next;
            }
    
            int mid = count / 2;
    
            temp = head;
    
            for (int i = 0; i < mid - 1; i++) {
                temp = temp->next;
            }
    
            ListNode* del = temp->next;
            temp->next = del->next;
            delete del;
    
            return head;
        }
    };
    
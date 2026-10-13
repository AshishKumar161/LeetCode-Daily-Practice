class Solution {
    public:
        ListNode* addOne(ListNode* head) {

            ListNode* temp = head;
            long long number = 0;
    
            while (temp != NULL) {
                number = number * 10 + temp->val;
                temp = temp->next;
            }

            number = number + 1;
    
            ListNode* newHead = NULL;
    
            while (number > 0) {
                int rem = number % 10;
    
                ListNode* newNode = new ListNode(rem);
                newNode->next = newHead;
                newHead = newNode;
    
                number = number / 10;
            }
    
            return newHead;
        }
    };
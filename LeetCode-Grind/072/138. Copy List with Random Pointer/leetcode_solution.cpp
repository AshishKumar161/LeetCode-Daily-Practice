class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if (head == NULL) return NULL;
    
            Node* newHead = new Node(head->val);
            
            Node* temp = head->next;    
            Node* newTemp = newHead;    
    
            while (temp != NULL) {
                newTemp->next = new Node(temp->val);
                newTemp = newTemp->next;
                temp = temp->next;
            }
          
            temp = head;
            newTemp = newHead;
    
            while (temp != NULL) {
                if (temp->random != NULL) {
                   
                    Node* p1 = head;
                    Node* p2 = newHead;
                    
                    while (p1 != temp->random) {
                        p1 = p1->next;
                        p2 = p2->next;
                    }
                    newTemp->random = p2;
                }
                
                temp = temp->next;
                newTemp = newTemp->next;
            }
    
            return newHead;
        }
    };
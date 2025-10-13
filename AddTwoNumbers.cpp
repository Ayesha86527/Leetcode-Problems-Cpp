class Solution {
public:
    void insertAtEnd(ListNode*& head, ListNode* new_node){
        if (head == NULL){
            head = new_node;
            new_node->next = NULL;
        }
        else {
            ListNode* temp = head;
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = NULL;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    ListNode* temp3 = NULL;
    int carry = 0;
    
    while (temp1 != NULL || temp2 != NULL || carry != 0){
        int sum = carry;
        
        if (temp1 != NULL) {
            sum += temp1->val;
            temp1 = temp1->next;
        }
        
        if (temp2 != NULL) {
            sum += temp2->val;
            temp2 = temp2->next;
        }
        
        carry = sum / 10;
        sum = sum % 10;
        
        ListNode* new_node = new ListNode(sum);
        insertAtEnd(temp3, new_node);
    }
    return temp3;  
    }
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp = head;
    int count1 = 0;
    while (temp != NULL){
        count1 += 1;
        temp = temp->next;
    }
    
    int stop = count1 - n;
    if (stop == 0) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }
    
    temp = head;
    int count2 = 0;
    while (temp != NULL){
        count2 += 1;
        if (count2 == stop){  
            break;
        }
        temp = temp->next;  
    }
    
    ListNode* del = temp->next;
    temp->next = temp->next->next;
    delete del;
    return head;
    }
};
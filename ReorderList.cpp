class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;          
            curr = next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split and reverse second half
        ListNode* second = reverseList(slow->next);
        slow->next = NULL;
        
        // Merge
        ListNode* first = head;
        while (second != NULL) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            
            first->next = second;
            second->next = temp1;
            
            first = temp1;
            second = temp2;
        }
    }
};

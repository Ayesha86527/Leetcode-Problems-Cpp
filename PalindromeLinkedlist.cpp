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
    
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Find middle
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse second half
        ListNode* second = reverseList(slow->next);
        slow->next = NULL;
        
        // Compare
        ListNode* first = head;
        while (second != NULL) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        
        return true;
    }
};
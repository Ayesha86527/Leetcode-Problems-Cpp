class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return NULL;
        
        Node* temp = head;
        while (temp != NULL) {
            if (temp->child != NULL) {
                Node* next_node = temp->next;
                
                temp->next = temp->child;
                temp->child->prev = temp;
                
                Node* child_end = temp->child;
                while (child_end->next != NULL) {
                    child_end = child_end->next;
                }
                
                if (next_node != NULL) {
                    child_end->next = next_node;
                    next_node->prev = child_end;
                }
                
                temp->child = NULL;
            }
            temp = temp->next;
        }
        return head;
    }
};
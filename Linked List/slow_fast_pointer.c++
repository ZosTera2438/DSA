ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head->next == NULL) {
        return NULL;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (n > 0) {
        fast = fast->next;
        n--;
    }
    
    if (fast == NULL) {
        return head->next;
    }
    
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    
    slow->next = slow->next->next;
    return head;
}




/*
middle node for even list:-
    slow = fast = head;  
    n -> n -> (n) -> n

    slow = head; fast = head->next;
    n -> (n) -> n -> n
*/
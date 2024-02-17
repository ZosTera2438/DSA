// NOTE: pre and cur has same position only next changes, next attaches to node infront of pre
// cur is reversed list head

node* reverseKNodes(node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    
    int length = lengthOfLinkedList(head);
    
    node* dummyHead = new node(0);
    dummyHead->next = head;
    
    node* pre = dummyHead;
    node* cur;
    node* nex;
    
    while(length >= k) {
        cur = pre->next; // prev was reassigned to cur (reversed list head)
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return dummyHead->next;
}

// Approch 2: all change positions, curr points to prev until curr is null
// prev is reverserd list head
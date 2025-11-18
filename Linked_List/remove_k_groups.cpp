Node* kReverse(Node* head, int k) {
    // 1. Check if there are at least k nodes left
    Node* cursor = head;
    for(int i = 0; i < k; i++) {
        if(!cursor) return head; // Not enough nodes, return as is
        cursor = cursor->next;
    }

    // 2. Reverse the first k nodes
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    
    for(int i = 0; i < k; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // 3. Recursively call for the rest of the list and link it
    // 'head' is now the tail of the current group
    head->next = kReverse(curr, k); 

    // 'prev' is the new head of the current group
    return prev; 
}
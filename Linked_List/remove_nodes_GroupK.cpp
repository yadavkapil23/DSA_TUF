Node* getKthNode(Node* temp, int k) {
    while(temp && k > 1) {
        temp = temp->next;
        k--;
    }
    return temp;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while(curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* kReverse(Node* head, int k) {
    if(!head || k <= 1) return head;

    Node* temp = head;
    Node* prevNode = NULL;
    Node* newHead = NULL;

    while(temp) {
        Node* kThNode = getKthNode(temp, k);
        if(kThNode == NULL) {
            if(prevNode) prevNode->next = temp;
            break;
        }

        Node* nextnode = kThNode->next;
        kThNode->next = NULL;   // cut block

        Node* reversedHead = reverseList(temp);

        if(!newHead) newHead = reversedHead;
        else prevNode->next = reversedHead;

        prevNode = temp;
        temp = nextnode;
    }

    return newHead;
}

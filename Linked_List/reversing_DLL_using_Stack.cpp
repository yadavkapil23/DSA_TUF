void reverseList(Node* head) {
    stack<int> st;
    Node* temp = head;

    // Step 1: Push all elements of the linked list into the stack
    while (temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Step 2: Pop from stack and update linked list data
    temp = head;
    while (temp != NULL) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
}
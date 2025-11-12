#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to delete Nth node from the end
ListNode* deleteNthFromEnd(ListNode* head, int N) {
    int cnt = 0;
    ListNode* temp = head;

    // Step 1: Count total nodes
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    // Step 2: If N == count, delete the head node
    if (cnt == N) {
        ListNode* newHead = head->next;
        delete head; // or free(head);
        return newHead;
    }

    // Step 3: Find the (cnt - N)th node
    int res = cnt - N;
    temp = head;

    while (temp != NULL) {
        res--;
        if (res == 0)
            break;
        temp = temp->next;
    }

    // Step 4: Delete the Nth node from the end
    ListNode* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;

    return head;
}

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5, delete 2nd from end → 1 2 3 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    head = deleteNthFromEnd(head, 2);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}

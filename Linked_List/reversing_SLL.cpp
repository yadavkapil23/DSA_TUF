class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            next = curr->next;  //save the next node in next ptr.
            curr->next = prev;  //flip the pointer from next to prev.
            prev = curr;  //move the prev to curr
            curr = next;  //move the curr to next.
        }
        return prev;
    }
};
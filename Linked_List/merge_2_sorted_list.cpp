class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
while(p1 && p2){
        if(p1->val <= p2->val){
            tail->next = p1;
            p1 = p1->next;
        }
        else{
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
}

        while(p1){
            tail->next = p1;
            tail = tail->next;
            p1 = p1->next;
        }
        while(p2){
            tail->next=p2;
            tail = tail->next;
            p2=p2->next;
        }

            return dummy->next;
    }
};
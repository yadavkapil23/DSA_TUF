class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        //move fast pointer ahead by n steps.
        for(int i=1 ; i<=n ; i++){
            fast = fast->next;
        }

        if(fast == nullptr){
            ListNode* todelete = head;
            head=head->next;
            delete(todelete);
            return head;
        }
        while(fast->next != nullptr){
            fast = fast->next;
            slow=slow->next;
        }



        //slow is the position to dlete.
        ListNode* todeleted = slow->next;
        slow->next = slow->next->next;
        delete(todeleted);
       return head;
    }
};
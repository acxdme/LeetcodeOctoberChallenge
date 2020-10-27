/*
Time complexity : O(N)
Space complexity : O(1) 
My approach :  floyd cycle detection algorithm.
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* slow =head;
        ListNode* fast =head;
        
        do
        {
            slow = slow->next;
            if(fast == NULL or fast->next== NULL) return NULL;
             fast =fast->next->next;
        }while(fast!=slow);
            
       slow = head;
        while(fast!= slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        
        return slow;
        
    }
};

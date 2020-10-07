/*
Time complexity : O(N)
Space complexity : O(1)
My approach : Pick the last node and insert it in the begining  k%size times.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    int getsize(ListNode* head)
    {
        if(head==NULL) return 0;
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        
        return count;
    }
    
    ListNode* getLastone(ListNode* head)
    {
        ListNode* temp= head;
        while(temp->next!=NULL)
            temp=temp->next;
        
        return temp;
    }
    
    ListNode* getbeforeLast(ListNode* head)
    {
        ListNode* temp1 =head;
        while(temp1->next->next!=NULL)
             temp1 = temp1->next;
        
        return temp1;
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        int m =getsize(head);
        if(m==0) return NULL;
        k = k % m;
        
        for(int i=0;i<k;i++)
        {
            ListNode* lastone = getLastone(head);
            ListNode* beforeLast = getbeforeLast(head);
            beforeLast->next =NULL;
             lastone->next = head;
            head=lastone;
        }
        
        
        return head;
        
    }
};

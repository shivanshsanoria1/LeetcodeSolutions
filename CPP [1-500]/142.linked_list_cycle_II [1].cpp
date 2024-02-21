/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* startOfLoop(ListNode* head, ListNode* start2)
    {
        ListNode* start1=head;
        while(start1 != start2)
        {
            start1= start1->next;
            start2= start2->next;
        }
        return start1;
    }

    ListNode *detectCycle(ListNode *head) { //Floyd's cycle detection algo.
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow= slow->next;
            fast= fast->next->next;
            if(slow == fast) //cycle found
                return startOfLoop(head,slow);
        }
        return NULL; //no cycle found
    }
};
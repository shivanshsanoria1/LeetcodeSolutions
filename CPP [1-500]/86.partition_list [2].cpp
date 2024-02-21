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
    ListNode* partition(ListNode* head, int x) { //S.C.=O(1)
        if(head==NULL || head->next==NULL) //0 or 1 node in LL
            return head;
        ListNode *dummy = new ListNode(-1); //dummy node
        dummy->next=head;
        ListNode *prev=dummy, *curr=head, *end=head;
        while(end->next!=NULL) //end pointer at last node
            end=end->next;
        ListNode *new_end=end;
        while(curr!=end)
        {
            if(curr->val >= x)
            {
                prev->next=curr->next;
                curr->next=NULL;
                new_end->next=curr;
                new_end=curr;
                curr=prev->next;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        if(new_end!=end && curr->val >= x) //last node val (in original LL) >= x
        {
            prev->next=curr->next;
            curr->next=NULL;
            new_end->next=curr;
        }
        return dummy->next;
    }
};
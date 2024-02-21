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
    ListNode* oddEvenList(ListNode* head) { //S.C.=O(1)
        if(head==NULL) //empty LL
            return head;
        ListNode *prev=head;
        ListNode *curr=head->next; //start from 2nd node
        ListNode *end=head;
        while(end->next!=NULL) //end pointer at last node
            end=end->next;
        ListNode *new_end=end;
        while(prev!=end && curr!=end)
        {
            prev->next=curr->next;
            curr->next=NULL;
            new_end->next=curr;
            new_end=curr;
            prev=prev->next;
            curr=prev->next;
        }
        if(new_end!=end && curr==end)
        {
            prev->next=curr->next;
            curr->next=NULL;
            new_end->next=curr;
            new_end=curr;
        }
        return head;
    }
};
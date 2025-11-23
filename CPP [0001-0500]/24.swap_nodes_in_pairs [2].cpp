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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) // LL of size 0 or 1 remain unchanged
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next=head;
        ListNode *curr=head;
        ListNode *left=dummy, *right=curr->next;
        while(curr!=NULL && curr->next!=NULL)
        {
            curr->next=right->next;
            right->next=curr;
            left->next=right;
            left=curr;
            curr=curr->next;
            if(curr!=NULL)
                right=curr->next;
        }
        head=dummy->next;
        delete dummy;
        return head;
    }
};
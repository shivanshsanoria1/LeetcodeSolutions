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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL) //find middle node, ie, 'slow'
        {
            slow= slow->next;
            fast= fast->next->next;
        }
        ListNode *prev=NULL, *temp=NULL;
        while(slow!=NULL) //reverse LL from 'slow' to end
        {
            temp= slow->next;
            slow->next= prev;
            prev= slow;
            slow= temp;
        }
        ListNode *left=head, *right=prev;
        while(right!=NULL) //check the non-reversed and the reversed halves
        {
            if(left->val != right->val)
                return false;
            left= left->next;
            right= right->next;
        }
        return true;
    }
};
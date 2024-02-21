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
    ListNode* mergeInBetween(ListNode* head1, int a, int b, ListNode* head2) {
        ListNode *curr_a=head1, *curr_b=head1;
        while(b--)
        {
            a--;
            if(a > 0)
                curr_a=curr_a->next;
            curr_b=curr_b->next;
        }
        ListNode *end2=head2;
        while(end2->next!=NULL) //'end2' pointer at the last node of LL2
            end2=end2->next;
        curr_a->next = head2; //join LL1 ath node the LL2 1st node
        end2->next = curr_b->next; //join LL2 last node the LL1 (b+1)th node
        return head1;
    }
};
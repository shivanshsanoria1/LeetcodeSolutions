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
        ListNode *currA = head1;
        ListNode *currB = head1;
        
        while(b--)
        {
            a--;
            if(a > 0)
                currA = currA->next;
            currB = currB->next;
        }

        // pointer to the last node of LL2
        ListNode *end2 = head2;
        while(end2->next != nullptr) 
            end2 = end2->next;

        // join the (a-1)th node of LL1 to 0th node LL2
        currA->next = head2; 
        // join the last node of LL2 to (b+1)th node of LL1
        end2->next = currB->next;

        return head1;
    }
};
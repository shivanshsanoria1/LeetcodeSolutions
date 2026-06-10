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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
        ListNode *curr1=l1, *curr2=l2;
        ListNode *dummy = new ListNode(-1); // 1st node of the final LL
        ListNode *curr = dummy;
        int carry = 0;
        // run until both LLs becomes empty
        while(curr1 != NULL || curr2 != NULL)
        {
            int val1 = curr1 != NULL ? curr1->val : 0;
            int val2 = curr2 != NULL ? curr2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            if(curr1 != NULL)
                curr1 = curr1->next;
            if(curr2 != NULL)
                curr2 = curr2->next;
        }
        if(carry == 1) // final carry is generated from MSB
        {
            curr->next = new ListNode(1);
            curr = curr->next;
        }
        ListNode* head = dummy->next; // head of final LL
        delete dummy; // delete the dummy node
        return head;
    }
};
// numbers in LL1 and LL2 are given in LSB to MSB
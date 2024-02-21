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
    ListNode *reverseLL(ListNode *head){
        ListNode *prev=NULL, *curr=head, *temp=NULL;
        while(curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1); //reverse LL1
        l2 = reverseLL(l2); //reverse LL2
        ListNode *curr1=l1, *curr2=l2;
        ListNode *dummy = new ListNode(-1); // 1st node of the final LL
        ListNode *curr = dummy;
        int carry = 0;
        while(curr1 != NULL && curr2 != NULL)
        {
            int sum = curr1->val + curr2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1 != NULL) // LL1 has more elements remaining
        {
            int sum = curr1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            curr1 = curr1->next;
        }
        while(curr2 != NULL) // LL2 has more elements remaining
        {
            int sum = curr2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            curr2 = curr2->next;
        }
        if(carry == 1) // final carry is generated from MSB
        {
            curr->next = new ListNode(1);
            curr = curr->next;
        }
        ListNode* head = dummy->next; // head of final LL
        delete dummy; // delete the dummy node
        head = reverseLL(head); // reverse final LL
        return head;
    }
};
// numbers in LL1 and LL2 are given in MSB to LSB
// similar to Leetcode 2: add two numbers and Leetcode 206: reverse linked list